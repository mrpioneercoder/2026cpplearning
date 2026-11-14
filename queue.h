#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int datetype;
typedef struct Node {
	datetype date;
	struct Node* next;
}qnode;
typedef struct queue {
	qnode* front;
	qnode* tail;
	int size;
}queue;
#ifdef __cplusplus
extern "C" {
#endif

void queueinit(queue* q);//初始化队列
void queuedestory(queue* q);//销毁队列
bool queueempty(queue* q);//判断队列是否为空
int queuesize(queue* q);//获取队列中有效元素的个数
datetype queuefront(queue* q);//获取队头元素
void enqueue(queue* q, datetype x);//将x入队
datetype dequeue(queue* q);//出队并返回队头元素

#ifdef __cplusplus
}
#endif
