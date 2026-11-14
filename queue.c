#include"queue.h"
void queueinit(queue*q)
{
	q->front = q->tail = (qnode*)malloc(sizeof(qnode));
	if (!q->front)
	{
		exit(1);
	}
	q->size = 0;
	q->front->date = -1;
	q->tail->next = NULL;
}
void enqueue(queue* q, datetype x)
{
	assert(q);
	assert(q->front);
	qnode* newnode = (qnode*)malloc(sizeof(qnode));
	if (!newnode)
	{
		exit(1);
	}
	newnode->date = x;
	q->tail->next = newnode;
	q->tail = newnode;
	newnode->next = NULL;
	q->size++;
}
datetype dequeue(queue* q)
{
	qnode* curnode = q->front->next;
	if (curnode->next == NULL)
	{
		q->tail = q->front;
	 }
	q->front->next = curnode->next;
	datetype x = curnode->date;
	free(curnode); 
	q->size--;
	return x;
}
bool queueempty(queue* q)
{
	assert(q);
	return q->size == 0;
}
int queuesize(queue* q)
{
	assert(q);
	return q->size;
}
datetype queuefront(queue* q)
{
	assert(q);
	assert(!queueempty(q));
	return q->front->next->date;
}
void queuedestory(queue* q)
{
	assert(q);
	qnode* cur = q->front->next;
	while (cur)
	{
		qnode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(q->front);
	q->front = q->tail = NULL;
	q->size = 0;
}