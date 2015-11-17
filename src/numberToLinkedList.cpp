/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node *list;

list insert(list l1, int n)
{
	list temp;
	temp = (list)malloc(sizeof(struct node *));
	temp->num = l1->num;
	l1->num = n;
	temp->next = l1->next;
	l1->next = temp;
	return l1;
}


struct node * numberToLinkedList(int N) {
	int n;
	list l1;
	int c = 0;
	l1 = (list)malloc(sizeof(struct node *));
	l1->num = NULL;
	l1->next = NULL;
	if (N<0)
	{
		N = -(N);
	}
	while (N > 0)
	{
		n = N % 10;
		c++;
		if (c == 1)
		{
			l1->num = n;
		}
		else
			l1 = insert(l1, n);
		N = N / 10;
	}
	return l1;
}