#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int datetype;
typedef struct stack {
	int* arr;
	int top;
	int capacity;
}stack;

stack* initstack(stack* newnode);
void enrichstack(stack* s);
void pushstack(stack* s, datetype x);
void escstack(stack* s);
