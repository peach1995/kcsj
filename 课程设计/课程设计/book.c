#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "main.h"

bookInfo *headBook = NULL;     //����ͼ������ͷָ�� 
void bookmuenu()
{
	int n;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U		ͼ����Ϣ				�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("\t�U		 1 - �鿴����ͼ����Ϣ			�U\n");
	printf("\t�U		 2 - ����ͼ��				�U\n");
	printf("\t�U		 3 - ����ͼ��				�U\n");
	printf("\t�U		 4 - ɾ��ͼ��				�U\n");
	printf("\t�U		 5 - ����				�U\n");
	printf("\t�U		 6 - �˳�				�U\n");
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\n              ���빦��(1-6):");
	scanf("%d", &n);/*����ѡ���ܵı��*/
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
	//	printf("�ڴ�ռ�����ʧ�ܡ�\n");
	//	exit(1);
	//}
	headBook = p;
	p1 = p;
	//p1->next = NULL;
	FILE *fp;
	fp = fopen("book.dat", "rb");
	if (fp == NULL)
	{
		printf("�����ļ�book.dat");
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
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U				ͼ����Ϣ			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("\t�U\t ͼ���� ͼ������	������	�۸�	�Ƿ���	�U	\n");
	if (headBook->next==NULL)
		printf("\t�U\t\tû��ͼ�顣					�U\n");
	else
	{
		while (p->next != NULL)
		{
			printf("\t�U\t  %lld     %s\t\t%s \t%.2f\t    %c		�U\n", p->Number, p->bookName, p->pulishName, p->Price, p->Borrow);
			p = p->next;
			booknum++;
		} 
	}
	printf("\t�U\t\t\t\t\t��%d����			�U\n", booknum);
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t���롰1������  ���롰2���ص����˵�\n");
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
		printf("�ڴ����ʧ�ܡ�");
		exit(1);
	}
	printf("\n\n\n\n\n");
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U				����ͼ��			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("\t\t����ͼ���ţ�");
	scanf("%lld", &i);
	p->Number = i;
	printf("\t\t����ͼ�����ƣ�");
	scanf("%s", c);
	strcpy(p->bookName, c);
	printf("\t\t����ͼ������磺");
	scanf("%s", b);
	strcpy(p->pulishName, b);
	printf("\t\t�����뵥��:");
	scanf("%f", &f);
	p->Price = f;
	p->Borrow = 'N';
	p->next = headBook;
	headBook = p;
	printf("¼��ɹ���");
	bookmuenu();
}
void searchBook()
{
	long int Num;
	int searchNum=0,n=0;
	bookInfo *p = NULL;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U				����ͼ��			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	p = headBook;
	if (headBook->next == NULL)
	{
		printf("\t�U\t\tû��ͼ�顣					�U\n");
		printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("\t���롰1������  ���롰2���ص����˵�\n");
		scanf("%d", &n);
		choice(n, 4);
	}
	else
	{
		printf("\t�U������ҵ���ı���:");
		scanf("%d", &Num);
		do{
			if (p->Number == Num)
			{
				printf("\t�U\t ͼ���� ͼ������	������	�۸�	�Ƿ���	�U	\n");
				printf("\t�U\t  %lld     %s\t\t%s \t%.2f\t    %c		�U\n", p->Number, p->bookName, p->pulishName, p->Price, p->Borrow);
				searchNum++;
			}
			p = p->next;
		} while (p->next != NULL);
	}
	if (searchNum == 0)
		printf("\t\t\tû��ƥ���ͼ�顣\n");
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t���롰1������  ���롰2���ص����˵�\n");
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
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U				ɾ��ͼ��			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	p = headBook;
	if (headBook->next == NULL)
	{
		printf("\t\t\tû��ͼ�顣\n");
		printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("\t���롰1������  ���롰2���ص����˵�\n");
		scanf("%d", &n);
		choice(n, 4);
	}
	else
	{
		printf("\t����ɾ��ͼ����:");
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
			printf("\t\t\t\tɾ���ɹ���\n");
		}
	}
	if (Del == 0)
		printf("\t\tû�����ͼ�顣\n");
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t���롰1������  ���롰2���ص����˵�\n");
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
		printf("\tû�����ݿ��Ա�д�롣\n");
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