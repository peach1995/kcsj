#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "student.h"
#include "borrow.h"
void mainmenu();
void inquire();
void choice(int n, int num);
void file_init();
char ch[2];



int main(void)
{
	studentInit();
	book_init();
	mainmenu();
	system("pause");
	return 0;
}
void mainmenu()
{
	int n;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════╗\n");
	printf("\t║		图书管理系统				║\n");
	printf("\t╠═══════════════════════════╣\n");
	printf("\t║		 1 - 图书信息				║\n");
	printf("\t║		 2 - 学生信息				║\n");
	printf("\t║		 3 - 借、还书登记			║\n");
	printf("\t║		 4 - 退出				║\n");
	printf("\t╚═══════════════════════════╝\n");
	printf("\n              输入功能(1-4):");
	scanf("%d", &n);/*输入选择功能的编号*/
	choice(n, 1);
}
void choice(int n, int num)
{
	int aa;
	while (n)
	{
		switch (n)
		{
		case 1:
			switch (num)
			{
			case 1:bookmuenu(); break;
			case 2:showAllBook(); break;
			case 3:showAllStu(); break;
			case 4:bookmuenu(); break;
			case 5:studentmuenu(); break;
			}
			break;
		case 2:
			switch (num)
			{
			case 1:studentmuenu(); break;
			case 2:searchBook(); break;
			case 3:searchStu(); break;
			case 4:mainmenu(); break;
			case 5:mainmenu(); break;
			}
			break;
		case 3:
			switch (num)
			{
			case 2:addBook(); break;
			case 3:addStu(); break;
			}
			break;
		case 4:
			switch (num)
			{
			case 1:saveStu(); saveBook(); exit(0);
			case 2:delBook();
			case 3:delStu();
			}
			break;
			case 5:switch (num)
			{
			case 2:mainmenu(); break;
			case 3:mainmenu(); break;
			}
			break;
		case 6:
			switch (num)
			{
			case 2:saveBook(); exit(0);
			case 3:saveStu(); exit(0);
			}
		default: printf("\t\t\t输入错误,请重新输入: "); scanf("%d", &aa); choice(aa, num); break;
		}
	}
}