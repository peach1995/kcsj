#pragma once
#ifndef __STUDENT_H_
#define __STUDENT_H_
typedef struct
{
	long long int ID;
	char Name[9];
	char Department[41];
	int borrowNum;
	float debtNum;
	struct studentInfo *next;
}studentInfo;




void studentmuenu();
void studentInit();
void showAllStu();
void addStu();
void searchStu();
void delStu();
void saveStu();

#endif
