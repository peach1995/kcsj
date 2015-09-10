#ifndef  __BOOK_H
#define __BOOK_H
typedef struct
{
	int year;
	char mouth;
	char dath;
}time;
typedef struct 
{
	long long int Number;
	char bookName[41];         //最多名字20个
	char pulishName[41];       //最多名字20个
	float Price;
	char Borrow;
	int studentNumber;
	time outtime;
	time inttime;
	float finePrice;
	struct bookInfo *next;
}bookInfo;



void bookmuenu();
void book_init();
void showAllBook(); 
void addBook();
void searchBook();
void delBook();
void saveBook();
#endif // ! __BOOK_H
