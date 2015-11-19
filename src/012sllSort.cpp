/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node *position;
typedef struct node *list;

void swap(list ll, position p, position q)
{
	int t;
	t = p->data;
	p->data = q->data;
	q->data = t;
}
position endpo(list ll)
{
	list t = ll;
	while (t->next != NULL)
		t = t->next;
	return t->next;
}

void sll_012_sort(struct node *head){
	position p, q;
	for (p = head; p != endpo(head); p = p->next)
	{
		for (q = p->next; q != endpo(head); q = q->next)
		{
			if (p->data > q->data)
				swap(head, p, q);
		}
	}
}