#include"link.h"
link* newcode(int n)
{
	link* newnode = (link*)malloc(sizeof(link));
	newnode->num = n;
	newnode->next = NULL;
	return newnode;
}
link* x(link* h1, link* h2)
{
	link* head=NULL, * tail=NULL;
	if (h1 == NULL)
	{
		head  = h2;
		return head;
	}
	if (h2 == NULL)
	{
		head  = h1;
		return head;
	}
	while (h1 && h2)
	{
		if (h1->num <= h2->num)
		{
			if (head == NULL)
			{
				head = tail = h1;
			}
			else
			{
				tail->next = h1;
				tail = h1;
			}
			h1 = h1->next;
		}
		else 
		{
			if (head == NULL)
			{
				head = tail = h2;
			}
			else
			{
				tail->next = h2;
				tail = h2;
			}
			h2 = h2->next;
		}
	}
	if (h1 == NULL)
	{
		tail->next = h2;
	}
	if (h2 == NULL)
	{
		tail->next = h1;
	}
	return head;
}