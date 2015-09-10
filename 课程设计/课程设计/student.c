#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "main.h"

studentInfo  *headStu = NULL;      //定义学生链表头指针 
void studentmuenu()
{
	int n;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════╗\n");
	printf("\t║		学生信息				║\n");
	printf("\t╠═══════════════════════════╣\n");
	printf("\t║\t 1 - 查看所有学生信息				║\n");
	printf("\t║\t 2 - 搜索学生					║\n");
	printf("\t║\t 3 - 增加学生					║\n");
	printf("\t║\t 4 - 删除学生					║\n");
	printf("\t║\t 5 - 返回					║\n");
	printf("\t║\t 6 - 退出					║\n");
	printf("\t╚═══════════════════════════╝\n");
	printf("\n              输入功能(1-6):");
	scanf("%d", &n);/*输入选择功能的编号*/
	choice(n, 3);
}
void studentInit()
{
	char c;
	int i = 0;
	studentInfo *p = NULL;
	studentInfo *p1 = NULL;
	//p = (studentInfo *)malloc(sizeof(studentInfo));
	//memset(p, 0, sizeof(studentInfo));
	//if (p == NULL)
	//{
	//	printf("内存空间申请失败。\n");
	//	exit(1);
	//}
	headStu = p;
	p1 = p;
	//p1->next = NULL;
	FILE *fp;
	fp = fopen("student.dat", "rb");
	if (fp == NULL)
	{
		printf("创建文件student.dat");
		fp = fopen("student.dat", "wb");
		fclose(fp);
		fp = fopen("student.dat", "rb");
	}
	while (!feof(fp))
	{
		p = (studentInfo *)malloc(sizeof(studentInfo));
		memset(p, 0, sizeof(studentInfo));
		fread(p, sizeof(studentInfo), 1, fp);
		if (!(NULL == p1))
		{
			p1->next = p;
			p1 = p;
		}
		else
		{
			headStu = p;
			p1 = p;
		}
	}
	p->next = NULL;
	fclose(fp);
}
void showAllStu()
{
	int n = 0, stuNum = 0;
	system("cls");
	studentInfo *p = NULL;
	p = headStu;
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║				学生信息			║\n");
	printf("\t╠═══════════════════════════════╣\n");
	printf("\t║学生学号  学生姓名	院系名称\t借书数	欠款		║	\n");
	if (p->next == NULL)
		printf("\t║\t\t没有学生信息。					║\n");
	else
	{
		p = headStu;
		while (p->next != NULL)
		{
			printf("\t║%lld\t\t%s\t%s\t\t  %d\t%.2f		║\n",  p->ID, p->Name, p->Department, p->borrowNum,p->debtNum);
			p = p->next;
			stuNum++;
		} 
	}
	printf("\t║\t\t\t\t\t共%d学生			║\n", stuNum);
	printf("\t╚═══════════════════════════════╝\n");
	printf("\t输入“1”返回  输入“2”回到主菜单\n");
	scanf("%d", &n);
	choice(n, 5);
}
void addStu()
{
	system("cls");
	long long int i;
	char c[41];
	char b[41];
	float f;
	studentInfo *p = NULL;
	p = (studentInfo*)malloc(sizeof(studentInfo));
	if (p == NULL)
	{
		printf("内存分配失败。");
		exit(1);
	}
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║				增添学生			║\n");
	printf("\t╠═══════════════════════════════╣\n");
	printf("\t\t输入学生学号：");
	scanf("%lld", &i);
	p->ID = i;
	printf("\t\t输入学生姓名：");
	scanf("%s", c);
	strcpy(p->Name, c);
	printf("\t\t输入学院学院：");
	scanf("%s", b);
	strcpy(p->Department, b);
	p->borrowNum = 0;
	p->debtNum = 0;
	p->next = headStu;
	headStu = p;
	printf("录入成功！");
	studentmuenu();
}
void searchStu()
{
	long int Num;
	int searchNum = 0, n = 0;
	studentInfo *p = NULL;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║				查找学生			║\n");
	printf("\t╠═══════════════════════════════╣\n");
	p = headStu;
	if (headStu->next == NULL)
	{
		printf("\t║\t\t没有学生信息。					║\n");
		printf("\t╚═══════════════════════════════╝\n");
		printf("\t输入“1”返回  输入“2”回到主菜单\n");
		scanf("%d", &n);
		choice(n, 5);
	}
	else
	{
		printf("\t║输入查找的书的编码:");
		scanf("%d", &Num);
		do {
			if (p->ID == Num)
			{
				printf("\t║学生学号  学生姓名	院系名称\t借书数	欠款		║	\n");
				printf("\t║%lld     %s\t%s\t\t  %d\t%.2f		║\n", p->ID, p->Name, p->Department, p->borrowNum, p->debtNum);
				searchNum++;
			}
			p = p->next;
		} while (p->next != NULL);
	}
	if (searchNum == 0)
		printf("\t\t\t没有匹配的学生信息。\n");
	printf("\t╚═══════════════════════════════╝\n");
	printf("\t输入“1”返回  输入“2”回到主菜单\n");
	scanf("%d", &n);
	choice(n, 5);
}
void delStu()
{
	long int Num = 0;
	char Del = 0;
	int n = 0;
	studentInfo *p = NULL;
	studentInfo *p1 = NULL;
	p = headStu;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║				删除学生信息			║\n");
	printf("\t╠═══════════════════════════════╣\n");
	p = headStu;
	if (headStu->next == NULL)
	{
		printf("\t\t\t没有学生。\n");
		printf("\t╚═══════════════════════════════╝\n");
		printf("\t输入“1”返回  输入“2”回到主菜单\n");
		scanf("%d", &n);
		choice(n, 5);
	}
	else
	{
		printf("\t输入删除图书编号:");
		scanf("%d", &Num);
		while (p->ID != Num && p->next != NULL)
		{
			p1 = p;
			p = p->next;
		}
		if (p->ID == Num)
		{
			Del = 1;
			if (p == headStu)
			{
				headStu = p->next;
			}
			else
			{
				p1->next = p->next;
			}
			free(p);
			p = NULL;
			printf("\t\t\t\t删除成功。\n");
		}
	}
	if (Del == 0)
		printf("\t\t没有相关学生信息。\n");
	printf("\t╚═══════════════════════════════╝\n");
	printf("\t输入“1”返回  输入“2”回到主菜单\n");
	scanf("%d", &n);
	choice(n, 5);
}
void saveStu()
{
	studentInfo *p = NULL;
	p = headStu;
	FILE *fp;
	fp = fopen("student.dat", "wb");
	if (NULL == p->next)
	{
		printf("\t没有数据可以被写入。\n");
	}
	else
	{
		p = headStu;
		while (!(NULL == p->next))
		{
			fwrite(p, sizeof(studentInfo), 1, fp);
			p = p->next;
		}
	}
}