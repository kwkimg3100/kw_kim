#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <malloc.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define MAX 30 //최대 고객 등록수

void write();   // 글 작성하는 함수
void list();    // 목록 보여주는 함수
void list_m();
void list_g(); //guest전용 게시판
void show(struct node *pNode);   // 실제 목록을 생성하는 함수(노드 출력)
//void delete(struct node *dnode);  // 글 삭제하는 함수
void delete(int z);
void gotoxy(int x, int y);  // 커서 위치 이동을 위한 함수
int getx();
int gety();
void seek(int z);
void seek1(int z);
void seek2(int z);
void menu();
void regist();
void l_ch(char ID2, char PW2, struct regist1 *snode);

typedef struct node{
	char writer[10];
	char title[20];
	char content[1000];
	int h; // 조회수
	struct node *pNext;
}node;

typedef struct regist1{
	char ID[15];
	char PW[15];
	char e_mail[25];
	struct regist1 *pNext;
}regist1;

node head, tail;
regist1 head1, tail1;

struct node *inode = NULL;
struct regist1 *rnode = NULL;

char ID[15];
char PW[15];

int main(void){
	system("mode con:cols=77 lines=24");
	char p;
	head1.pNext = &tail;           //
	tail.pNext = NULL;            //   연결리스트 구성
	tail1.pNext = NULL;			 //
	//while (1){
		menu();	//  메뉴함수로 이동
	//}
	system("cls");
	printf("프로그램 종료합니다\n");
	return 0;
}

void write(){
	inode = (struct node *)malloc(sizeof(struct node));
	FILE *file;
	system("cls");
	printf("작성자 : \n");
	fflush(stdin);
	printf("게시글 제목 : \n");
	printf("내용 : \n");
	gotoxy(8, 0);
	gets(inode->writer);
	gotoxy(13, 1);                                          //연결리스트에 새로운 노드를 생성시키는 함수
	gets(inode->title);
	gotoxy(6, 2);
	gets(inode->content);
	inode->h = 1;
	file = fopen(inode->title,"w");                         // 파일 함수
	fprintf(file, "작성자 : %s\n게시글 제목 : %s\n내용 : %s",inode->writer, inode->title, inode->content);        // 작성자 제목 내용을 모두 입력해야 오류가 안남 입력하지 않으면
	fclose(file);																							      // 초기화 되지 않은 값이 들어가기 때문에 오류가남

	inode->pNext = head.pNext;
	head.pNext = inode;	
}

/*
void delete(struct node *dnode){  //시작주소의 다음것이 삭제됨
	if (dnode->pNext != NULL){
		struct node *delnode = dnode->pNext;
		dnode->pNext = delnode->pNext;
		free(delnode);
		list();
	}
}
*/
void delete(int z){
	switch (z){
		case 4:                                          // 커서의 위치를 읽어서 위치에따라 삭제시키는 함수
			if (head.pNext != NULL){
				struct node *delnode = head.pNext;
				head.pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 5:
			if (head.pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext;
				head.pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 6:
			if (head.pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext;
				head.pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 7:
			if (head.pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 8:
			if (head.pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 9:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 10:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 11:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 12:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 13:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 14:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 15:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 16:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 17:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 18:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 19:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
		case 20:
			if (head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext != NULL){
				struct node *delnode = head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
				head.pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext = delnode->pNext;
				free(delnode);
				list();
			}
	}
}

void show(struct node *pNode){
	struct node *showNode = pNode;
	time_t timer;
	struct tm *t;
	timer = time(NULL);
	t = localtime(&timer);
	int day = t->tm_mday;
	int hour = t->tm_hour;
	int min = t->tm_min;
	
	printf("%50s", showNode->title);
	printf("%9s", showNode->writer);                       //연결리스트의 보여주기 함수
	printf("%5d", inode->h);
	printf("%6d-%d:%d",day,hour,min);
	if (showNode->pNext != NULL){
		printf("\n");
		show(showNode->pNext);
	}	
}

void list(){
	system("cls");
	printf(">manager mode\n");
	printf("============================================================================\n");
	printf("| 번호 |		   제목			  | 글쓴이 | 조회수 | 날짜 |\n");
	printf("============================================================================\n");
	if (head.pNext != NULL){
		show(head.pNext);
	}
	gotoxy(0, 20);
	printf("============================================================================");
	printf("	명령 : <↕> 게시글 선택	<w> 게시글 쓰기	<ENTER> 게시글 보기\n	<d> 게시글 삭제	<u> 로그인	<q> 종료");
	gotoxy(0, 4);
	int key1;
	int z= 4;
	int *y;
	do{
		y = &z;
		fflush(stdin);
		key1 = getch();
		if (key1 == 119){
			write();
			list();
		}
		if (key1 == 117){
			menu();
		}
		if (key1 == 13)
		{
			seek(z);// enter기능
		}
		if (key1 == 100){ //삭제기능
					delete(z);
		}
		else if(key1 == 0xE0 || key1 == 0){
			key1 = getch();
		switch (key1){
			case DOWN:
				*y += 1;
				gotoxy(0, z);
				
				if (z == 20){
					z = 4;
					gotoxy(0, 4);
				}
				break;
			case UP:
				*y -= 1;
				gotoxy(0, z);
				if (z == 3){
					z = 19;
					gotoxy(0, 19);
				}
				break;
			}
		}
	} while (key1 != 'q');
}

void list_m(){
	system("cls");
	printf(">member mode\n");
	printf("============================================================================\n");
	printf("| 번호 |		   제목			  | 글쓴이 | 조회수 | 날짜 |\n");
	printf("============================================================================\n");
	if (head.pNext != NULL){
		show(head.pNext);
	}
	gotoxy(0, 20);
	printf("============================================================================");
	printf("	명령 : <↕> 게시글 선택	<w> 게시글 쓰기	<ENTER> 게시글 보기\n	<u> 로그아웃	<q> 종료");
	gotoxy(0, 4);
	int key1;
	int z = 4;
	int *y;
	do{
		y = &z;
		fflush(stdin);
		key1 = getch();
		if (key1 == 119){
			write();
			list_m();
		}
		if (key1 == 117){
			menu();
		}
		if (key1 == 13)
		{
			seek2(z);// enter기능
		}
		else if (key1 == 0xE0 || key1 == 0){
			key1 = getch();
			switch (key1){
			case DOWN:
				*y += 1;
				gotoxy(0, z);

				if (z == 20){
					z = 4;
					gotoxy(0, 4);
				}
				break;
			case UP:
				*y -= 1;
				gotoxy(0, z);
				if (z == 3){
					z = 19;
					gotoxy(0, 19);
				}
				break;
			}
		}
	} while (key1 != 'q');
}

void list_g(){
	system("cls");
	printf(">guest mode\n");
	printf("============================================================================\n");
	printf("| 번호 |		   제목			  | 글쓴이 | 조회수 | 날짜 |\n");
	printf("============================================================================\n");
	if (head.pNext != NULL){
		show(head.pNext);                                                   // 게시글이 있으면 게스글을 보여주는 함수
	}
	gotoxy(0, 20);
	printf("============================================================================");
	printf("	명령 : <↕> 게시글 선택		<ENTER> 게시글 보기\n	<u> 로그인		<r> 회원가입		<q> 종료");
	gotoxy(0, 4);
	int key1;
	int z = 4;
	int *y;
	do{
		y = &z;
		fflush(stdin);
		key1 = getch();                                       //입력받는다
		if (key1 == 117){
			menu();                                 //아스키코드가 117이면 메뉴로이동
		}
		if (key1 == 13)                                       //아스키코드가 13이면 엔터기능을하는 (게시글보기함수로 이동)
		{
			seek1(z);// enter기능
		}
		if (key1 == 114){                                     // 아스키코드가 114이면 회원가입함수로 이동
			regist();
		}
		else if (key1 == 0xE0 || key1 == 0){                  // 방향키는 처음에 코드가 0xE0 또는 0이기때문에 방향키 인지확인하고 맞으면
			key1 = getch();                                   // 방향키가 2바이트인데 getch는 1바이트만 받기때문에 한번더 입력받는다.
			switch (key1){                                    // 아스키코드가 방향키 아래를 뜻하는것이면 
			case DOWN:
				*y += 1;                                      // 커서의 위치를 이동시킨다 아래로
				gotoxy(0, z);

				if (z == 20){
					z = 4;                                    // 커서의 위치가 20이면 커서를 4로 이동
					gotoxy(0, 4);                             
				}
				break;
			case UP:                                          // 아스키코드가 방향키 위를 뜻하는것이면
				*y -= 1;
				gotoxy(0, z);
				if (z == 3){
					z = 19;                                   // 커서가 3에 있으면 
					gotoxy(0, 19);                            // 커서를 19로 이동
				}
				break;
			}
		}
	} while (key1 != 'q');                                    // q를 입력하기전까지 반복
}

void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

	return pos;
}

int getx() {
	CONSOLE_SCREEN_BUFFER_INFO csb;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csb);
	return csb.dwCursorPosition.X;
}

int gety() {
	CONSOLE_SCREEN_BUFFER_INFO csb;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csb);
	return csb.dwCursorPosition.Y;
}

void seek(int z){
	char u = NULL;
	do{
		fflush(stdin);                  ////이 함수는 커서의 위치를 읽어서 엔터키를 누르면 해당 게시글이 보이도록 하는 함수 (관리자전용 함수)
		
		switch (z){
		case 4:
			if (inode != NULL){
				system("cls");
				printf("작성자 : %s\n", inode->writer);
				printf("게시글 제목 : %s\n", inode->title);
				printf("내용 : %s\n", inode->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				++(inode->h);
				u = getch();
			}
			else
				list();
			break;
		case 5:
			if ((inode->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext)->title);
				printf("내용 : %s\n", (inode->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				++(inode->pNext->h);
				u = getch();
			}
			else
				list();
			break;
		case 6:
			if ((inode->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();	
			}
			else
				list();
			break;
		case 7:
			if ((inode->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 8:
			if ((inode->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 9:
			if ((inode->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 10:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 11:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 12:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 13:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 14:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 15:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 16:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 17:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 18:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 19:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		case 20:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list();
			break;
		}
	} while (u != 'u');
	list();
}
void seek1(int z){
	char u = NULL;
	do{
		fflush(stdin);                  //이 함수는 커서의 위치를 읽어서 엔터키를 누르면 해당 게시글이 보이도록 하는 함수 (게스트전용 함수)

		switch (z){
		case 4:
			if (inode != NULL){
				system("cls");
				printf("작성자 : %s\n", inode->writer);
				printf("게시글 제목 : %s\n", inode->title);
				printf("내용 : %s\n", inode->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				++(inode->h);
				u = getch();
			}
			else
				list_g();
			break;
		case 5:
			if ((inode->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext)->title);
				printf("내용 : %s\n", (inode->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				++(inode->pNext->h);
				u = getch();
			}
			else
				list_g();
			break;
		case 6:
			if ((inode->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 7:
			if ((inode->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 8:
			if ((inode->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 9:
			if ((inode->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 10:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 11:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 12:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 13:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 14:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 15:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 16:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 17:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 18:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 19:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		case 20:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_g();
			break;
		}
	} while (u != 'u');
	list_g();
}

void seek2(int z){
	char u = NULL;
	do{
		fflush(stdin);                  ////이 함수는 커서의 위치를 읽어서 엔터키를 누르면 해당 게시글이 보이도록 하는 함수 (관리자전용 함수)

		switch (z){
		case 4:
			if (inode != NULL){
				system("cls");
				printf("작성자 : %s\n", inode->writer);
				printf("게시글 제목 : %s\n", inode->title);
				printf("내용 : %s\n", inode->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				++(inode->h);
				u = getch();
			}
			else
				list_m();
			break;
		case 5:
			if ((inode->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext)->title);
				printf("내용 : %s\n", (inode->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				++(inode->pNext->h);
				u = getch();
			}
			else
				list_m();
			break;
		case 6:
			if ((inode->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 7:
			if ((inode->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 8:
			if ((inode->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 9:
			if ((inode->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 10:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 11:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 12:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 13:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 14:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 15:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 16:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 17:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 18:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 19:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		case 20:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("작성자 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("게시글 제목 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("내용 : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("명령 : <u> 뒤로가기");
				u = getch();
			}
			else
				list_m();
			break;
		}
	} while (u != 'u');
	list_m();
}

void regist(){
	system("cls");

	rnode = (struct regist1 *)malloc(sizeof(struct regist1));
	
		printf("\n\n\n\n\n");
		printf("				  회원가입\n");
		printf("			  ************************\n");
		printf("			  ID :\n");
		printf("			  PW :\n");                            
		printf("			  e-mail:\n");
		printf("			  ************************\n");
		gotoxy(30, 7);
		gets(rnode->ID);
		gotoxy(30, 8);
		gets(rnode->PW);                                          //회원가입 함수
		gotoxy(33, 9);
		gets(rnode->e_mail);

		rnode->pNext = head1.pNext;                               //연결리스트에 입력한 값들의 노드를 새로 생성
		head1.pNext = rnode;

		system("cls");
		menu();                                          //회원가입후에 로그인하도록 로그인 함수로 이동
}

void menu(){
	system("cls");
	//char ID[15];
	//char PW[15];
	int i,n;
	char ch;
	printf("  \n");
	printf("    ##             ##                                                ##\n");
	printf("        # ####  ########  # #####   #######    # ####      #####  ########\n");
	printf("    ##  ##    #    ##     ##       #       #   ##    #    #     #    ##\n");
	printf("    ##  #     #    ##     #          #######   #     #    #######    ##\n");
	printf("    ##  #     #    ##     #        #       #   #     #    #          ##\n");
	printf("    ##  #     #    ##     #       #        #   #     #    #     #    ##\n");
	printf("    ##  #     #     ##    #        ######## #  #     #     #####      ##\n\n");
	printf("	      처음이시면 ID guest PW guest로 로그인 해주세요.\n\n");
	printf("			   *********************\n");
	printf("			   ID :\n");
	printf("			   PW :\n");
	printf("			   *********************\n\n\n");
	printf("			    수 123 알고리즘 9조");
	gotoxy(31,12);
	scanf("%s",ID);    // 아이디 입력
	//gets(ID);
	gotoxy(31, 13);                                  
	/*n = 0;
	while ((ch = getch()) != 13)
	{
		PW[n] = ch;
		n++;
		printf("*");
	}*/
	scanf("%s",PW);					//패스워드 입력
	//gets(PW);
	if (!strcmp(ID, "guest")){          //아이디가 guest일경우 
		if (!strcmp(PW, "guest")){      //패스워드가 guest인지 확인
			list_g();                   //맞으면 guest전용 게시판으로 이동
		}
		else{
			//printf("ID 혹은 PW를 잘못 입력하셨습니다.\n");
			l_ch(ID,PW,&head1);            //아니면 아이디체크 함수로이동
		}
	}
	else if (!strcmp(ID, "manager")){      // guest가 아닐경우 아이디가 manager인지 확인
		if (!strcmp(PW, "manager")){       // manager이면 패스워드도 manager이면
			list();                        // 관리자 게시판으로 이동
		}
		else
			l_ch(ID, PW, &head1);          //아니면 로그인체크함수로 이동
	}
	else{
		l_ch(ID, PW, &head1);              // 이것도
	}
}

void l_ch(char *ID2,char *PW2,struct regist1 *snode){
	struct regist1 *lnode = snode;
	if (lnode->pNext != NULL){
		if (strcmp(lnode->pNext->ID, ID2) == 0){
			if (strcmp(lnode->pNext->PW, PW2) == 0){
				list_m();	
			}
			else
				l_ch(ID, PW, lnode->pNext);
		}
		else{
			l_ch(ID, PW, lnode->pNext);
		}
		l_ch(ID,PW,lnode->pNext);
	}
	else{
		menu();
	}
}
/*char *ID1[10][MAX];
char *PW1[10][MAX];*/