#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "main.h"

bookInfo *headBook = NULL;     //定义图书链表头指针 
void bookmuenu()
{
	int n;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════╗\n");
	printf("\t║		图书信息				║\n");
	printf("\t╠═══════════════════════════╣\n");
	printf("\t║		 1 - 查看所有图书信息			║\n");
	printf("\t║		 2 - 搜索图书				║\n");
	printf("\t║		 3 - 增加图书				║\n");
	printf("\t║		 4 - 删除图书				║\n");
	printf("\t║		 5 - 返回				║\n");
	printf("\t║		 6 - 退出				║\n");
	printf("\t╚═══════════════════════════╝\n");
	printf("\n              输入功能(1-6):");
	scanf("%d", &n);/*输入选择功能的编号*/
	choice(n, 2);
}
void book_init()
{
	char c;
	int i = 0;
	bookInfo *p = NULL;
	bookInfo *p1 = NULL;
	//p = (bookInfo *)malloc(sizeof(bookInfo));
	//memset(p, 0, sizeof(bookInfo));
	//if (p == NULL)
	//{
	//	printf("内存空间申请失败。\n");
	//	exit(1);
	//}
	headBook = p;
	p1 = p;
	//p1->next = NULL;
	FILE *fp;
	fp = fopen("book.dat", "rb");
	if (fp == NULL)
	{
		printf("创建文件book.dat");
		fp = fopen("book.dat", "wb");
		fclose(fp);
		fp = fopen("book.dat", "rb");
	}
	while (!feof(fp))
	{
		p = (bookInfo *)malloc(sizeof(bookInfo));
		memset(p, 0, sizeof(bookInfo));
		fread(p, sizeof(bookInfo), 1, fp);
		if (!(NULL == p1))
		{
			p1->next = p;
			p1 = p;
		}
		else
		{
			headBook = p;
			p1 = p;
		}
	}
	p ->next=NULL;
	fclose(fp);
}
void showAllBook()
{
	int n=0,booknum=0;
	system("cls");
	bookInfo *p = NULL;
	p = headBook;
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║				图书信息			║\n");
	printf("\t╠═══════════════════════════════╣\n");
	printf("\t║\t 图书编号 图书名称	出版社	价格	是否借出	║	\n");
	if (headBook->next==NULL)
		printf("\t║\t\t没有图书。					║\n");
	else
	{
		while (p->next != NULL)
		{
			printf("\t║\t  %lld     %s\t\t%s \t%.2f\t    %c		║\n", p->Number, p->bookName, p->pulishName, p->Price, p->Borrow);
			p = p->next;
			booknum++;
		} 
	}
	printf("\t║\t\t\t\t\t共%d本书			║\n", booknum);
	printf("\t╚═══════════════════════════════╝\n");
	printf("\t输入“1”返回  输入“2”回到主菜单\n");
	scanf("%d", &n);
	choice(n, 4);
}
void addBook()
{
	system("cls");
	long long int i;
	char c[41];
	char b[41];
	float f;
	bookInfo *p = NULL;
	p = (bookInfo *)malloc(sizeof(bookInfo));
	if (p == NULL)
	{
		printf("内存分配失败。");
		exit(1);
	}
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║				增添图书			║\n");
	printf("\t╠═══════════════════════════════╣\n");
	printf("\t\t输入图书编号：");
	scanf("%lld", &i);
	p->Number = i;
	printf("\t\t输入图书名称：");
	scanf("%s", c);
	strcpy(p->bookName, c);
	printf("\t\t输入图书出版社：");
	scanf("%s", b);
	strcpy(p->pulishName, b);
	printf("\t\t请输入单价:");
	scanf("%f", &f);
	p->Price = f;
	p->Borrow = 'N';
	p->next = headBook;
	headBook = p;
	printf("录入成功！");
	bookmuenu();
}
void searchBook()
{
	long int Num;
	int searchNum=0,n=0;
	bookInfo *p = NULL;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║				查找图书			║\n");
	printf("\t╠═══════════════════════════════╣\n");
	p = headBook;
	if (headBook->next == NULL)
	{
		printf("\t║\t\t没有图书。					║\n");
		printf("\t╚═══════════════════════════════╝\n");
		printf("\t输入“1”返回  输入“2”回到主菜单\n");
		scanf("%d", &n);
		choice(n, 4);
	}
	else
	{
		printf("\t║输入查找的书的编码:");
		scanf("%d", &Num);
		do{
			if (p->Number == Num)
			{
				printf("\t║\t 图书编号 图书名称	出版社	价格	是否借出	║	\n");
				printf("\t║\t  %lld     %s\t\t%s \t%.2f\t    %c		║\n", p->Number, p->bookName, p->pulishName, p->Price, p->Borrow);
				searchNum++;
			}
			p = p->next;
		} while (p->next != NULL);
	}
	if (searchNum == 0)
		printf("\t\t\t没有匹配的图书。\n");
	printf("\t╚═══════════════════════════════╝\n");
	printf("\t输入“1”返回  输入“2”回到主菜单\n");
	scanf("%d", &n);
	choice(n, 4);
}
void delBook()
{
	long int Num=0;
	char Del=0;
	int n = 0;
	bookInfo *p = NULL;
	bookInfo *p1 = NULL;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════════╗\n");
	printf("\t║				删除图书			║\n");
	printf("\t╠═══════════════════════════════╣\n");
	p = headBook;
	if (headBook->next == NULL)
	{
		printf("\t\t\t没有图书。\n");
		printf("\t╚═══════════════════════════════╝\n");
		printf("\t输入“1”返回  输入“2”回到主菜单\n");
		scanf("%d", &n);
		choice(n, 4);
	}
	else
	{
		printf("\t输入删除图书编号:");
		scanf("%d", &Num);
		while (p->Number != Num && p->next != NULL)
		{
			p1 = p;
			p = p->next;
		}
		if (p->Number == Num)
		{
			Del = 1;
			if (p == headBook)
			{
				headBook = p->next;
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
		printf("\t\t没有相关图书。\n");
	printf("\t╚═══════════════════════════════╝\n");
	printf("\t输入“1”返回  输入“2”回到主菜单\n");
	scanf("%d", &n);
	choice(n, 4);
}
void saveBook()
{
	bookInfo *p = NULL;
	p = headBook;
	FILE *fp;
	fp = fopen("book.dat", "wb");
	if (NULL == p->next)
	{
		printf("\t没有数据可以被写入。\n");
	}
	else
	{
		while (!(NULL == p->next))
		{
			fwrite(p, sizeof(bookInfo), 1, fp);
			p = p->next;
		}
	}
}