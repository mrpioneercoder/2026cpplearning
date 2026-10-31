#pragma once
#include<stdio.h>
#include<Stdlib.h>
#include<assert.h>
typedef int datetype;
typedef struct linklist
{
	datetype num;
	struct linklist* next;
}link;
link* newlist(int n);
void printlist(link* phead);
void buynode(link* phead, int i,datetype n);
int amountnode(link* phead);
link* findnodebynum(link* phead, int key);
link* findnode(link* phead, int n);
void deletenode(link* phead, int n);

