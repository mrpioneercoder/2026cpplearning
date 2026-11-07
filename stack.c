#include"stack.h"
stack* initstack(stack* newnode)
{
	if (!newnode)
	{
		exit(1);
	}
	newnode->arr = (datetype*)malloc(4 * sizeof(datetype));
	newnode->top = 0;
	newnode->capacity = 4;
	return newnode;
}
void enrichstack(stack* s)
{
	stack* cur = s;
	if (s->top == s->capacity - 1)
	{
		cur->arr = (datetype*)realloc(s->arr,sizeof(datetype) * s->capacity * 2);
		s->capacity *= 2;
	}
}
void pushstack(stack* s, datetype x)
{
	if (s->top == s->capacity - 1)
	{
		enrichstack(s);
	}
	s->arr[s->top] = x;
	s->top++;
}
void escstack(stack* s)
{
	--s->top;
}
