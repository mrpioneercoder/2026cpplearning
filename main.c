#include"tree.h"
int main()
{
	heap p;
	treeinit(& p);
	pushheap(&p, 1);
	pushheap(&p, 2);
	pushheap(&p, 3);
	pushheap(&p, 4);
	pushheap(&p, 5);
	pushheap(&p, 6);
	
	for (int i = 0; i < 6; i++)
	{
		printf("%d\n", p.a[i]);
	}
	deleteheap(&p);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", p.a[i]);
	}
	return 0;
}