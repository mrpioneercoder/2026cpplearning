#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct link {
	int num;
	struct link* next;
}link;
link* newcode(int n);
link* x(link* h1, link* h2);

