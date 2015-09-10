#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "borrow.h"


void borrowmune()
{
	int n;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t╔═══════════════════════════╗\n");
	printf("\t║			借还书登记			║\n");
	printf("\t╠═══════════════════════════╣\n");
	printf("\t║			1 - 借书					║\n");
	printf("\t║			2 - 还书				║\n");
	printf("\t║			3 - 退出				║\n");
	printf("\t╚═══════════════════════════╝\n");
	printf("\n              输入功能(1-4):");
	scanf("%d", &n);/*输入选择功能的编号*/
	choice(n, 6);
}