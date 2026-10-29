#include"sqlist.h"
int main()
{ 
	sqlist ps;
	 sqlistinit(&ps);
	 
	 sqlistinsert(&ps, 0, 12);
	 sqlistinsert(&ps, 0, 11);
	 sqlistinsert(&ps, 0, 21);
	 sqlistinsert(&ps, 0, 111);
	 sqlistinsert(&ps, 0, 131);
	 sqlistinsert(&ps, 0, 333);
	 sqlistinsert(&ps, 0,334);
	 sqlistinsert(&ps, 0, 55);
	 
	 destorylist(&ps, 1);
	 printlist(&ps);
	 printf("\n");
	 destoryalllist(&ps);
	 
	 printlist(&ps);
	return 0;
}