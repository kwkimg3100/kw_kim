#!/bin/bash
wget -O gisang www.weather.go.kr/weather/main-now-weather.jsp?myPointCode=1159068000
grep 'dl class\|dd class="temp"' gisang > tmp1
rm -f gisang
var=2
var1=2
var2=2
var3=2
while read i
do
if [ `expr $var % 2` = "0" ]
then
echo $i >> tmp2
var=`expr $var + 1`
else
var=`expr $var + 1`
fi
done < tmp1
awk '!x[$0]++' tmp2 > region_tmp
rm -f tmp2
while read i
do
i=`echo ${i#*_}`
i=`echo ${i%'"'*}`
echo $i >> region
done < region_tmp
rm -f region_tmp
while read i
do
if [ `expr $var2 % 2` = "1" ]
then
i=`echo ${i#*>}`
i=`echo ${i%<*}`
echo $i >> tmpt
fi
var2=`expr $var2 + 1`
done < tmp1
sed -i 's///' tmpt
rm -f tmp1
paste region tmpt > syn
echo "set terminal svg
set output \"region_temp.svg\"
set xtic rotate 90
set ylabel \"temperature\"
plot \"syn\" using 2:xtic(1) notitle with boxes" | gnuplot
#gnuplot << EOF			#this method doesn't work while something's mounting
#	set terminal svg
#	set output "region_temp.svg"
#	set xtic rotate 90
#	set ylabel "temperature"
#	plot "syn" using 2:xtic(1) notitle with boxes
#EOF
rm -f region syn tmpt
