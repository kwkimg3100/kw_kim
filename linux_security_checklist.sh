#! /bin/bash

tmp=`echo $UID`
if [ "$tmp" != "0" ]
then
echo "Please execute at root"
exit 1
fi

tmp=`uname -s`
if [ "$tmp" != "Linux" ]
then
echo "This machine is not Linux."
echo "We are recommend to execute at Centos Version 7"
echo "This script wrote based on Centos Version 7"
exit 1
fi

#####################################################################################
#PATH
#####################################################################################
echo '------------------------------------------------------------------------------'
echo '[PATH CHECK]'
echo $PATH > test
if grep '\.' test 
then
echo '.dir was found'
echo '------------------------------------------------------------------------------'
else
echo '$PATH is OK'
echo '------------------------------------------------------------------------------'
fi
rm -f test
#####################################################################################
#DISK
#####################################################################################
echo '[DISK CHECK]'
if df -h | egrep "[8-9][0-9]%|100%"
#if df -h | awk '$5 >= 80'
then
df -h | head -1
echo 'DISK Use% exceed 80%'
echo '------------------------------------------------------------------------------'
else
echo 'DISK is OK'
echo '------------------------------------------------------------------------------'
fi
#####################################################################################
#/dev CHECK
#####################################################################################
echo '[/dev backdoor CHECK]'
find /dev/ -type f -exec ls -l {} \; > test
if [ -s test ]
then
cat test
echo 'Suspicion file was detected. Check it.'
echo '------------------------------------------------------------------------------'
else
echo '/dev is OK'
echo '------------------------------------------------------------------------------'
fi
rm -f test
#####################################################################################
#login.def CHECK
#####################################################################################
echo '[Password set up CHECK]'
echo '*Standard of KISA*'
#cat /etc/login.defs | awk '$2 ~ /[0-9]$/' > test
#login.defs
grep ^PASS /etc/login.defs > test
#if [ 180 -ge $(grep PASS_MAX_DAYS test | awk '{print $2}') ]
if [ 180 -ge `grep PASS_MAX_DAYS test | awk '{print $2}'` ]
then
echo 'login.defs : PASS_MAX_DAYS is OK.'
else
echo 'login.defs : PASS_MAX_DAYS exceed 180days. Check it.'
fi
if [ 8 -le `grep PASS_MIN_LEN test | awk '{print $2}'` ]
then
echo 'login.defs : PASS_MAX_LEN is OK.'
else
echo "login.defs : PASS_MAX_LEN is `grep PASS_MIN_LEN test | awk '{print $2}'`. Check it"
fi
rm -f test
#####################################################################################
grep "minlen\|dcredit\|ucredit\|lcredit\|ocredit" /etc/security/pwquality.conf > test
if [ '#' = `grep minlen /test | awk '{print $1}'` ]
then 
echo 'pwquality.conf : minlen is inactive. Check it'
elif [ 8 -le `grep minlen /test | awk '{print $3}'` ]
then
echo 'pwquality.conf : minlen is OK.'
else 
echo "pwquality.conf : minlen is `grep minlen /test | awk '{print $3}'`. Check it."
fi
#####################################################################################
if [ '#' = `grep dcredit /test | awk '{print $1}'` ]
then
echo 'pwquality.conf : dcredit is inactive. Check it'
elif [ '-1' -ne `grep dcredit /test | awk '{print $3}'` ]
then
echo "pwquality.conf : dcredit is `grep dcredit /test | awk '{print $3}'`. Check it"
else
echo 'pwquality.conf : dcredit is OK.'
fi
#####################################################################################
if [ '#' = `grep ucredit /test | awk '{print $1}'` ]
then
echo 'pwquality.conf : ucredit is inactive. Check it'
elif [ '-1' -ne `grep ucredit /test | awk '{print $3}'` ]
then
echo "pwquality.conf : ucredit is `grep ucredit /test | awk '{print $3}'`. Check it"
else
echo 'pwquality.conf : ucredit is OK.'
fi
#####################################################################################
if [ '#' = `grep lcredit /test | awk '{print $1}'` ]
then
echo 'pwquality.conf : lcredit is inactive. Check it'
elif [ '-1' -ne `grep lcredit /test | awk '{print $3}'` ]
then
echo "pwquality.conf : lcredit is `grep lcredit /test | awk '{print $3}'`. Check it"
else
echo 'pwquality.conf : lcredit is OK.'
fi
#####################################################################################
if [ '#' = `grep ocredit /test | awk '{print $1}'` ]
then
echo 'pwquality.conf : ocredit is inactive. Check it'
echo '------------------------------------------------------------------------------'
elif [ '-1' -ne `grep ocredit /test | awk '{print $3}'` ]
then
echo "pwquality.conf : ocredit is `grep ocredit /test | awk '{print $3}'`. Check it"
echo '------------------------------------------------------------------------------'
else
echo 'pwquality.conf : ocredit is OK.'
echo '------------------------------------------------------------------------------'
fi
rm -f test
#####################################################################################
#sshd_config CHECK
#####################################################################################
echo '[SSH CHECK]'
exec < /etc/ssh/sshd_config
while read i
do
if [ `echo $i | wc -w` = "2" ]
then
echo $i >> test
elif [ `echo $i | wc -w` = "3" ]
then
echo $i >> test
fi
done
#####################################################################################
Get(){
grep -niw port test > test1
var=`cut -f1 -d':' test1`
sed -n "$var"p test > test1
} #test function
#####################################################################################
Get
if [ `cut -b1 test1` = "#" ]
then
echo "sshd_config : Port is inactive. Check it"
elif [ `awk '{print $2}' test1` = "22" ]
then
echo "sshd_config : Port is 22. Check it"
else
echo "sshd_config : Port is OK."
fi
#####################################################################################
grep -niw permitrootlogin test > test1
var=`cut -f1 -d':' test1`
sed -n "$var"p test > test1
if [ `cut -b1 test1` = "#" ]
then
echo "sshd_config : PermitRootLogin is inactive. Check it"
elif [ `awk '{print $2}' test1` = "yes" ]
then
echo "sshd_config : PermitRootLogin is Yes. Check it"
else
echo "sshd_config : PermitRootLogin is OK."
fi
#####################################################################################
grep -niw logingracetime test > test1
var=`cut -f1 -d':' test1`
sed -n "$var"p test > test1
if [ `cut -b1 test1` = "#" ]
then
echo "sshd_config : LoginGraceTime is inactive. Check it"
echo '------------------------------------------------------------------------------'
elif [ `grep -o '[0-9]*' test1` -le "2" ]
then
echo "sshd_config : LoginGraceTime is OK."
echo '------------------------------------------------------------------------------'
else
echo "sshd_config : LoginGraceTime is `grep -o '[0-9]*' test1`m. Check it"
echo '------------------------------------------------------------------------------'
fi
rm -f test test1
#####################################################################################
echo '[UNNECESSARY ACCOUNT CHECK]'
while read i
do
awk '{print $1}' >> test
done < /etc/passwd
cat test | awk -F# '{print $1}' > test1
awk -F: '{print $1}' test1 > temp
account=halt:mail:uucp:operator:games:gopher:ftp:nobody:dbus:usbmuxd:rpc:avahi-autoipd:nscd:vcsa:rtkit:abrt:apache:saslauth:avahi:postfix 
for num in $(seq 20)
do
#echo $account | cut -f"$num" -d':'
#echo $account | awk -F: '{print "\$num"}' #why working?
var=`echo $account | cut -f"$num" -d':'`
tmp=`grep $var temp`
if [ -n "$tmp" ]
then
echo "passwd : $tmp was found. Check it" 
fi
done
echo "Check finished"
echo '------------------------------------------------------------------------------'
rm -f test temp test1
#####################################################################################
echo '[ACCOUNT UID 0 CHECK]'
cat /etc/passwd | awk '{print $1}' > test
while read i
do
var=`echo ${i:0:1}`
if [ "$var" != "#" ]
then
echo $i >> tmp_f
fi
done < test
while read i
do
var=`echo $i | awk -F: '{print $3}'`
if [ "$var" = "0" ]
then
echo $i >> test5
fi
done < tmp_f
while read i
do
flag=0
var=`echo $i | awk -F: '{print $1}'`
if [ "$var" != "root" ]
then
flag=$(($flag+1))
echo "$var"_UID is 0. Check it
fi
done < test5
if [ "$flag" = "0" ]
then
echo "Account_UID is OK."
fi
echo '------------------------------------------------------------------------------'
rm -f test5 tmp_f test
#####################################################################################
echo '[ROOT COMMAND CHECK]'
echo -e "at\nmount\numount\ncrontab\nchange\nfinger\ntop\npstree\nw\nps\nwho\nfind\ndf\nnetstat\nifconfig\nlsof\nmake\ngcc\ng++\nc++" > test
while read i
do
find / -perm -00011 -name $i >> temp
while read var
do
tmp=`find $var -perm -00011 -name $i`
if [ -n "$tmp" ]
then
echo "\"$tmp\" change the permission"
fi
done < temp
rm -f temp
done < test
rm -f test
echo "Check finished"
echo '------------------------------------------------------------------------------'
#####################################################################################
echo '[FIREWALLD CHECK]'
i=`firewall-cmd --state`
if [ "$i" != "running" ]
then
echo "Active the firewall"
echo '------------------------------------------------------------------------------'
else
echo "firewalld is $i" 
i=`firewall-cmd --get-default-zone`
echo "firewall_"$i"_service : `firewall-cmd --zone=$i --list-service`"
echo '------------------------------------------------------------------------------'
fi
#####################################################################################
echo '[HISTORY DATE SET CHECK]'
grep HISTTIMEFORMAT /etc/profile | awk '{print $1}' > test
flag=0
while read i
do
var=`expr substr $i 1 1`
if [ "$var" = "#" ]
then
flag=$(($flag+1))
fi
done < test
if [ "$flag" != "0" ]
then
echo "Set HISTTIMEFORMAT at /etc/profile"
echo "If you attack from someone"
echo "It will help you"
echo '------------------------------------------------------------------------------'
elif [ "$flag" = "0" ]
then
echo "/etc/profile : HISTTIMEFORMAT is OK"
echo '------------------------------------------------------------------------------'
fi
rm -f test
#####################################################################################
echo '[TELNET CHECK]'
if [ -z `rpm -qa | grep telnet` ]
then
echo "telnet is OK"
echo '------------------------------------------------------------------------------'
else
echo "telnet command is active. Check it"
echo '------------------------------------------------------------------------------'
fi
#####################################################################################
echo '[RHOSTS FILE CHECK]'
find / -name "*.rhosts" > test
while read i
do
if [ -n "$i" ]
then
echo "\"$i\" check it"
fi
done < test
if [ -z "$i" ]
then
echo "Check finished"
fi
