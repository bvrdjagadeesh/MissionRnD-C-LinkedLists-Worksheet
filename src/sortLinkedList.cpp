/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

typedef struct node *position;
typedef struct node *list;

void swa(list ll, position p, position q)
{
	int t;
	t = p->num;
	p->num = q->num;
	q->num = t;
}
position endpos(list ll)
{
	list t = ll;
	while (t->next != NULL)
		t = t->next;
	return t;
}
struct node * sortLinkedList(struct node *head) {
	if (head!=NULL)
	{
		position p, q;
		for (p = head; p!=endpos(head); p = p->next)
		{
			for (q = p->next; q!=endpos(head); q = q->next)
			{
				if (p->num > q->num)
					swa(head, p, q);
			}
		}
		
		return head;
	}
	else
		return NULL;
}