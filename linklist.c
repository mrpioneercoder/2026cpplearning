#include"linklist.h"
link* newlist(int n)
{
	link* newnode = (link*)malloc(sizeof(link));
	newnode->num = n;
	newnode->next = NULL;
	return newnode;
 }
void printlist(link* phead)
{
	phead = phead->next;
	while (phead != NULL)
	{
		printf("%d->", phead->num);
		phead = phead->next;
	}
	printf("NULL");
}
int amountnode(link* phead)
{
	link* cur = phead->next;
	int j = 0;
	while (cur)
	{
		j++;
		cur = cur->next;
	}
	return j;
}
void buynode(link* phead,int i,datetype n)
{
	assert(phead);

	link* newnode = (link*)malloc(sizeof(link));
	int max = amountnode(phead);
	assert(i<=max);
	link* cur = phead; int j = 0;
	while (cur&&j<i)
	{
		cur = cur->next;
		j++;
	}
	newnode->next = cur->next;
	newnode->num = n;
	cur->next = newnode;
}
link* findnodebynum(link* phead,int key)
{
	int i = 1;
	link* cur = phead->next;
	while (cur) 
	{
		if (cur->num == key)
		{
			break;
		}
		cur = cur->next;
		i++;
	}
	return cur;
}
link* findnode(link* phead, int n)
{
	link* cur = phead->next;
	int i = 1;
	while (i < n)
	{
		cur = cur->next;
		i++;
	}
	return cur;
}
void deletenode(link* phead, int n)
{
	int i = 1;
	link* cur = phead->next;
	while (i < n-1)
	{
		cur=cur->next;
		i++;
	}
	link*pcur = cur->next;
	 cur->next=cur->next->next ;
	free(pcur);
	pcur = NULL;
}