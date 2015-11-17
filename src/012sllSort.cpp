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

void sll_012_sort(struct node *head){
	position p, q;
	for (p = head; p->next != NULL; p = p->next)
	{
		for (q = p->next; q->next != NULL; q = q->next)
		{
			if (p->data > q->data)
				swap(head, p, q);
		}
	}
	list temp;
	temp = (list)malloc(sizeof(struct node *));
	temp->data = head->data;
	temp->next = head->next;
	head->data = NULL;
	head->next = temp;
}