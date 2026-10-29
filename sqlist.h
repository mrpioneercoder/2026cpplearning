#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int datetype;

typedef struct sqlist {
	datetype*a;
	int num;
	int capacity;
}sqlist;
void sqlistinit(sqlist* ps);
sqlist* enrichlist(sqlist* ps);
void sqlistinsert(sqlist* ps, int i, datetype x);
void printlist(sqlist* ps);
void destorylist(sqlist* ps,int i);
void destoryalllist(sqlist* ps);

