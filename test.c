#include"link.h"
int main()
{
	link* h1 = newcode(2);
	h1->next = newcode(4);
	link* h2 = newcode(3);
	h2->next = newcode(5);
	link* head = x(h1, h2);
	link* cur = head;
	
	while (cur) {
		printf("%d->", cur->num);
		cur = cur->next;
	}
	printf("NULL");
	return 0;
}