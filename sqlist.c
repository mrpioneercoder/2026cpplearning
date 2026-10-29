#include"sqlist.h"
void sqlistinit(sqlist* ps)
{
	assert(ps != NULL);
	/*if (ps == NULL)
	{
		exit(-1);
	}*/
	ps->a = (datetype*)malloc(sizeof(datetype)*4);

	ps->num = 0;
	ps->capacity = 4;
}
sqlist* enrichlist(sqlist* ps)
{
	assert(ps);
	sqlist* pc = ps;
	pc->a = (datetype*)realloc(ps->a, sizeof(datetype) * ps->capacity * 2);
	ps->capacity *= 2;
	if (pc->a != NULL)
	{
		ps->a=pc->a;
	}
	else
	{
		perror(realloc);
	}
	return ps;
}
void sqlistinsert(sqlist* ps, int i, datetype x)
{
	assert(ps);
	assert(i <= ps->num);
	if (ps->num == ps->capacity)
	{
		sqlist* pc = ps;
		ps = enrichlist(pc);
	}
	for (int j = ps->num-1; j >= i ; j--)
	{
		ps->a[j+1] = ps->a[j ];
	}
	ps->a[i] = x;
	ps->num++;
}
void printlist(sqlist* ps)
{
	int i = 0;
	while (i < ps->num)
	{
		printf("%d  ",ps->a[i]);
		i++;
	}
}
void destorylist(sqlist* ps,int i)
{
	assert(i < ps->num - 1);
		ps->a[i] = ps->a[i + 1];
		i++;
		ps->num--;
	
}
void destoryalllist(sqlist* ps)
{
	free(ps->a);
	ps->num=0;
	ps->capacity = 0;
}