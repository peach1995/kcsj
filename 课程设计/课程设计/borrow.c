#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "borrow.h"


void borrowmune()
{
	int n;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t�U			�軹��Ǽ�			�U\n");
	printf("\t�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g\n");
	printf("\t�U			1 - ����					�U\n");
	printf("\t�U			2 - ����				�U\n");
	printf("\t�U			3 - �˳�				�U\n");
	printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	printf("\n              ���빦��(1-4):");
	scanf("%d", &n);/*����ѡ���ܵı��*/
	choice(n, 6);
}