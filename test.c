#include"linklist.h"
int main()
{
	link* phead = newlist(-1);
	phead->next = newlist(2); printlist(phead);
	printf("\n");
	buynode(phead,1,3);//按下标插入
	buynode(phead,2,4);//按下标插入
	buynode(phead,1,6);//按下标插入
	buynode(phead,1,5);//按下标插入
	buynode(phead,1,13);//按下标插入
	buynode(phead,1,33);//按下标插入
	printlist(phead); printf("\n");
	int n = amountnode(phead);//计算有效节点的个数
	printf("%d\n", n);
	/*printf("%p\n", phead);
	printf("%p\n", &phead);
	printf("%p\n", &(phead->next));*/
	link* cur1 = findnodebynum(phead, 2);
	printf("%d\n", cur1->num);
	link* cur2 = findnode(phead, 3);
		printf("%d\n",cur2->num);
		deletenode(phead, 3);
		printlist(phead);
	return 0;
}