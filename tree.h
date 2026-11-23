#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int datetype;
typedef struct tree {
	datetype* a;
	int capacity;
	int size;
}heap;
void treeinit(heap* p);
void swap(datetype* x, datetype* y);
void adjustup(datetype* a, int child);
void pushheap(heap* p, datetype x);
void adjustdown(datetype* a, int size, int parent);
void deleteheap(heap* p);