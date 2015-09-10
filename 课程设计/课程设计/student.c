#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "main.h"

studentInfo  *headStu = NULL;      //����ѧ������ͷָ�� 
void studentmuenu()
{
	int n;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U		ѧ����Ϣ				�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("\t�U\t 1 - �鿴����ѧ����Ϣ				�U\n");
	printf("\t�U\t 2 - ����ѧ��					�U\n");
	printf("\t�U\t 3 - ����ѧ��					�U\n");
	printf("\t�U\t 4 - ɾ��ѧ��					�U\n");
	printf("\t�U\t 5 - ����					�U\n");
	printf("\t�U\t 6 - �˳�					�U\n");
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\n              ���빦��(1-6):");
	scanf("%d", &n);/*����ѡ���ܵı��*/
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
	//	printf("�ڴ�ռ�����ʧ�ܡ�\n");
	//	exit(1);
	//}
	headStu = p;
	p1 = p;
	//p1->next = NULL;
	FILE *fp;
	fp = fopen("student.dat", "rb");
	if (fp == NULL)
	{
		printf("�����ļ�student.dat");
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
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U				ѧ����Ϣ			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("\t�Uѧ��ѧ��  ѧ������	Ժϵ����\t������	Ƿ��		�U	\n");
	if (p->next == NULL)
		printf("\t�U\t\tû��ѧ����Ϣ��					�U\n");
	else
	{
		p = headStu;
		while (p->next != NULL)
		{
			printf("\t�U%lld\t\t%s\t%s\t\t  %d\t%.2f		�U\n",  p->ID, p->Name, p->Department, p->borrowNum,p->debtNum);
			p = p->next;
			stuNum++;
		} 
	}
	printf("\t�U\t\t\t\t\t��%dѧ��			�U\n", stuNum);
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t���롰1������  ���롰2���ص����˵�\n");
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
		printf("�ڴ����ʧ�ܡ�");
		exit(1);
	}
	printf("\n\n\n\n\n");
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U				����ѧ��			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("\t\t����ѧ��ѧ�ţ�");
	scanf("%lld", &i);
	p->ID = i;
	printf("\t\t����ѧ��������");
	scanf("%s", c);
	strcpy(p->Name, c);
	printf("\t\t����ѧԺѧԺ��");
	scanf("%s", b);
	strcpy(p->Department, b);
	p->borrowNum = 0;
	p->debtNum = 0;
	p->next = headStu;
	headStu = p;
	printf("¼��ɹ���");
	studentmuenu();
}
void searchStu()
{
	long int Num;
	int searchNum = 0, n = 0;
	studentInfo *p = NULL;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U				����ѧ��			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	p = headStu;
	if (headStu->next == NULL)
	{
		printf("\t�U\t\tû��ѧ����Ϣ��					�U\n");
		printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("\t���롰1������  ���롰2���ص����˵�\n");
		scanf("%d", &n);
		choice(n, 5);
	}
	else
	{
		printf("\t�U������ҵ���ı���:");
		scanf("%d", &Num);
		do {
			if (p->ID == Num)
			{
				printf("\t�Uѧ��ѧ��  ѧ������	Ժϵ����\t������	Ƿ��		�U	\n");
				printf("\t�U%lld     %s\t%s\t\t  %d\t%.2f		�U\n", p->ID, p->Name, p->Department, p->borrowNum, p->debtNum);
				searchNum++;
			}
			p = p->next;
		} while (p->next != NULL);
	}
	if (searchNum == 0)
		printf("\t\t\tû��ƥ���ѧ����Ϣ��\n");
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t���롰1������  ���롰2���ص����˵�\n");
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
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U				ɾ��ѧ����Ϣ			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	p = headStu;
	if (headStu->next == NULL)
	{
		printf("\t\t\tû��ѧ����\n");
		printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		printf("\t���롰1������  ���롰2���ص����˵�\n");
		scanf("%d", &n);
		choice(n, 5);
	}
	else
	{
		printf("\t����ɾ��ͼ����:");
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
			printf("\t\t\t\tɾ���ɹ���\n");
		}
	}
	if (Del == 0)
		printf("\t\tû�����ѧ����Ϣ��\n");
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\t���롰1������  ���롰2���ص����˵�\n");
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
		printf("\tû�����ݿ��Ա�д�롣\n");
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