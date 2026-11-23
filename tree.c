#include"tree.h"
void treeinit(heap*p)
{
	assert(p != NULL);
	p->a = NULL;
	p->capacity = p->size = 0;
}
void swap(datetype* x, datetype* y)
{
	assert(x != NULL && y != NULL);
	int temp = *x;
	*x = *y;
	*y = temp;
}
void adjustup(datetype* a,int child)
{
	int parent = (child  - 1) / 2;
	while (parent >= 0)
	{
		if (a[child]>a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child  - 1) / 2;
		}
		else {
			break;
		}
	}
}
void pushheap(heap*p, datetype x)
{
	if (p->size == p->capacity)
	{
		int newcapacity = p->capacity == 0 ? 4 : p->capacity * 2;
		datetype* newa = (datetype*)realloc(p->a, sizeof(datetype) * newcapacity);
		if (newa == NULL)
	{
			exit(-1);
	}
		p->a = newa;
		p->capacity = newcapacity;
	}
	p->a[p->size ] = x;
	p->size++;
	adjustup(p->a, p->size - 1);
}
void adjustdown(datetype* a,int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		child = parent * 2 + 1;
		if (child + 1 < size && *(a + child) < *(a + child + 1))
		{
			child++;
		}
		if (*(a + parent) < *(a + child))
		{
			swap(&a[parent],&a[child]);
		}
		else {
			break;
		}
	}
	
	
}
void deleteheap(heap* p)
{
	swap(&p->a[0], &p->a[p->size - 1]);
	--p->size;
	adjustdown(p->a, p->size,0);

}