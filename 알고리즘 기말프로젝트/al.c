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
#define MAX 30 //�ִ� �� ��ϼ�

void write();   // �� �ۼ��ϴ� �Լ�
void list();    // ��� �����ִ� �Լ�
void list_m();
void list_g(); //guest���� �Խ���
void show(struct node *pNode);   // ���� ����� �����ϴ� �Լ�(��� ���)
//void delete(struct node *dnode);  // �� �����ϴ� �Լ�
void delete(int z);
void gotoxy(int x, int y);  // Ŀ�� ��ġ �̵��� ���� �Լ�
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
	int h; // ��ȸ��
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
	tail.pNext = NULL;            //   ���Ḯ��Ʈ ����
	tail1.pNext = NULL;			 //
	//while (1){
		menu();	//  �޴��Լ��� �̵�
	//}
	system("cls");
	printf("���α׷� �����մϴ�\n");
	return 0;
}

void write(){
	inode = (struct node *)malloc(sizeof(struct node));
	FILE *file;
	system("cls");
	printf("�ۼ��� : \n");
	fflush(stdin);
	printf("�Խñ� ���� : \n");
	printf("���� : \n");
	gotoxy(8, 0);
	gets(inode->writer);
	gotoxy(13, 1);                                          //���Ḯ��Ʈ�� ���ο� ��带 ������Ű�� �Լ�
	gets(inode->title);
	gotoxy(6, 2);
	gets(inode->content);
	inode->h = 1;
	file = fopen(inode->title,"w");                         // ���� �Լ�
	fprintf(file, "�ۼ��� : %s\n�Խñ� ���� : %s\n���� : %s",inode->writer, inode->title, inode->content);        // �ۼ��� ���� ������ ��� �Է��ؾ� ������ �ȳ� �Է����� ������
	fclose(file);																							      // �ʱ�ȭ ���� ���� ���� ���� ������ ��������

	inode->pNext = head.pNext;
	head.pNext = inode;	
}

/*
void delete(struct node *dnode){  //�����ּ��� �������� ������
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
		case 4:                                          // Ŀ���� ��ġ�� �о ��ġ������ ������Ű�� �Լ�
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
	printf("%9s", showNode->writer);                       //���Ḯ��Ʈ�� �����ֱ� �Լ�
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
	printf("| ��ȣ |		   ����			  | �۾��� | ��ȸ�� | ��¥ |\n");
	printf("============================================================================\n");
	if (head.pNext != NULL){
		show(head.pNext);
	}
	gotoxy(0, 20);
	printf("============================================================================");
	printf("	��� : <��> �Խñ� ����	<w> �Խñ� ����	<ENTER> �Խñ� ����\n	<d> �Խñ� ����	<u> �α���	<q> ����");
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
			seek(z);// enter���
		}
		if (key1 == 100){ //�������
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
	printf("| ��ȣ |		   ����			  | �۾��� | ��ȸ�� | ��¥ |\n");
	printf("============================================================================\n");
	if (head.pNext != NULL){
		show(head.pNext);
	}
	gotoxy(0, 20);
	printf("============================================================================");
	printf("	��� : <��> �Խñ� ����	<w> �Խñ� ����	<ENTER> �Խñ� ����\n	<u> �α׾ƿ�	<q> ����");
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
			seek2(z);// enter���
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
	printf("| ��ȣ |		   ����			  | �۾��� | ��ȸ�� | ��¥ |\n");
	printf("============================================================================\n");
	if (head.pNext != NULL){
		show(head.pNext);                                                   // �Խñ��� ������ �Խ����� �����ִ� �Լ�
	}
	gotoxy(0, 20);
	printf("============================================================================");
	printf("	��� : <��> �Խñ� ����		<ENTER> �Խñ� ����\n	<u> �α���		<r> ȸ������		<q> ����");
	gotoxy(0, 4);
	int key1;
	int z = 4;
	int *y;
	do{
		y = &z;
		fflush(stdin);
		key1 = getch();                                       //�Է¹޴´�
		if (key1 == 117){
			menu();                                 //�ƽ�Ű�ڵ尡 117�̸� �޴����̵�
		}
		if (key1 == 13)                                       //�ƽ�Ű�ڵ尡 13�̸� ���ͱ�����ϴ� (�Խñۺ����Լ��� �̵�)
		{
			seek1(z);// enter���
		}
		if (key1 == 114){                                     // �ƽ�Ű�ڵ尡 114�̸� ȸ�������Լ��� �̵�
			regist();
		}
		else if (key1 == 0xE0 || key1 == 0){                  // ����Ű�� ó���� �ڵ尡 0xE0 �Ǵ� 0�̱⶧���� ����Ű ����Ȯ���ϰ� ������
			key1 = getch();                                   // ����Ű�� 2����Ʈ�ε� getch�� 1����Ʈ�� �ޱ⶧���� �ѹ��� �Է¹޴´�.
			switch (key1){                                    // �ƽ�Ű�ڵ尡 ����Ű �Ʒ��� ���ϴ°��̸� 
			case DOWN:
				*y += 1;                                      // Ŀ���� ��ġ�� �̵���Ų�� �Ʒ���
				gotoxy(0, z);

				if (z == 20){
					z = 4;                                    // Ŀ���� ��ġ�� 20�̸� Ŀ���� 4�� �̵�
					gotoxy(0, 4);                             
				}
				break;
			case UP:                                          // �ƽ�Ű�ڵ尡 ����Ű ���� ���ϴ°��̸�
				*y -= 1;
				gotoxy(0, z);
				if (z == 3){
					z = 19;                                   // Ŀ���� 3�� ������ 
					gotoxy(0, 19);                            // Ŀ���� 19�� �̵�
				}
				break;
			}
		}
	} while (key1 != 'q');                                    // q�� �Է��ϱ������� �ݺ�
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
		fflush(stdin);                  ////�� �Լ��� Ŀ���� ��ġ�� �о ����Ű�� ������ �ش� �Խñ��� ���̵��� �ϴ� �Լ� (���������� �Լ�)
		
		switch (z){
		case 4:
			if (inode != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", inode->writer);
				printf("�Խñ� ���� : %s\n", inode->title);
				printf("���� : %s\n", inode->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				++(inode->h);
				u = getch();
			}
			else
				list();
			break;
		case 5:
			if ((inode->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext)->title);
				printf("���� : %s\n", (inode->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				++(inode->pNext->h);
				u = getch();
			}
			else
				list();
			break;
		case 6:
			if ((inode->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();	
			}
			else
				list();
			break;
		case 7:
			if ((inode->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 8:
			if ((inode->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 9:
			if ((inode->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 10:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 11:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 12:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 13:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 14:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 15:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 16:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 17:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 18:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 19:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list();
			break;
		case 20:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
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
		fflush(stdin);                  //�� �Լ��� Ŀ���� ��ġ�� �о ����Ű�� ������ �ش� �Խñ��� ���̵��� �ϴ� �Լ� (�Խ�Ʈ���� �Լ�)

		switch (z){
		case 4:
			if (inode != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", inode->writer);
				printf("�Խñ� ���� : %s\n", inode->title);
				printf("���� : %s\n", inode->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				++(inode->h);
				u = getch();
			}
			else
				list_g();
			break;
		case 5:
			if ((inode->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext)->title);
				printf("���� : %s\n", (inode->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				++(inode->pNext->h);
				u = getch();
			}
			else
				list_g();
			break;
		case 6:
			if ((inode->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 7:
			if ((inode->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 8:
			if ((inode->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 9:
			if ((inode->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 10:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 11:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 12:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 13:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 14:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 15:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 16:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 17:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 18:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 19:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_g();
			break;
		case 20:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
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
		fflush(stdin);                  ////�� �Լ��� Ŀ���� ��ġ�� �о ����Ű�� ������ �ش� �Խñ��� ���̵��� �ϴ� �Լ� (���������� �Լ�)

		switch (z){
		case 4:
			if (inode != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", inode->writer);
				printf("�Խñ� ���� : %s\n", inode->title);
				printf("���� : %s\n", inode->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				++(inode->h);
				u = getch();
			}
			else
				list_m();
			break;
		case 5:
			if ((inode->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext)->title);
				printf("���� : %s\n", (inode->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				++(inode->pNext->h);
				u = getch();
			}
			else
				list_m();
			break;
		case 6:
			if ((inode->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 7:
			if ((inode->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 8:
			if ((inode->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 9:
			if ((inode->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 10:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 11:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 12:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 13:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 14:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 15:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 16:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 17:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 18:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 19:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
				u = getch();
			}
			else
				list_m();
			break;
		case 20:
			if ((inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext) != NULL){
				system("cls");
				printf("�ۼ��� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->writer);
				printf("�Խñ� ���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->title);
				printf("���� : %s\n", (inode->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext->pNext)->content);
				gotoxy(0, 20);
				printf("============================================================================\n");
				printf("��� : <u> �ڷΰ���");
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
		printf("				  ȸ������\n");
		printf("			  ************************\n");
		printf("			  ID :\n");
		printf("			  PW :\n");                            
		printf("			  e-mail:\n");
		printf("			  ************************\n");
		gotoxy(30, 7);
		gets(rnode->ID);
		gotoxy(30, 8);
		gets(rnode->PW);                                          //ȸ������ �Լ�
		gotoxy(33, 9);
		gets(rnode->e_mail);

		rnode->pNext = head1.pNext;                               //���Ḯ��Ʈ�� �Է��� ������ ��带 ���� ����
		head1.pNext = rnode;

		system("cls");
		menu();                                          //ȸ�������Ŀ� �α����ϵ��� �α��� �Լ��� �̵�
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
	printf("	      ó���̽ø� ID guest PW guest�� �α��� ���ּ���.\n\n");
	printf("			   *********************\n");
	printf("			   ID :\n");
	printf("			   PW :\n");
	printf("			   *********************\n\n\n");
	printf("			    �� 123 �˰��� 9��");
	gotoxy(31,12);
	scanf("%s",ID);    // ���̵� �Է�
	//gets(ID);
	gotoxy(31, 13);                                  
	/*n = 0;
	while ((ch = getch()) != 13)
	{
		PW[n] = ch;
		n++;
		printf("*");
	}*/
	scanf("%s",PW);					//�н����� �Է�
	//gets(PW);
	if (!strcmp(ID, "guest")){          //���̵� guest�ϰ�� 
		if (!strcmp(PW, "guest")){      //�н����尡 guest���� Ȯ��
			list_g();                   //������ guest���� �Խ������� �̵�
		}
		else{
			//printf("ID Ȥ�� PW�� �߸� �Է��ϼ̽��ϴ�.\n");
			l_ch(ID,PW,&head1);            //�ƴϸ� ���̵�üũ �Լ����̵�
		}
	}
	else if (!strcmp(ID, "manager")){      // guest�� �ƴҰ�� ���̵� manager���� Ȯ��
		if (!strcmp(PW, "manager")){       // manager�̸� �н����嵵 manager�̸�
			list();                        // ������ �Խ������� �̵�
		}
		else
			l_ch(ID, PW, &head1);          //�ƴϸ� �α���üũ�Լ��� �̵�
	}
	else{
		l_ch(ID, PW, &head1);              // �̰͵�
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