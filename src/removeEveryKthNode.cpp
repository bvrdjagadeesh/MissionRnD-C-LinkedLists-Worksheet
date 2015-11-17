/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};
typedef struct node *position;
typedef struct node *list;
position prevpos(list ll, position p)
{
	position q = ll;
	while (q->next != p)
		q = q->next;
	return q;
}
struct node * removeEveryKthNode(struct node *head, int K) {
	if (K < 0 || head == NULL)
		return NULL;
	else if (K == 0)
		return 0;
	else if (K == 1)
		return NULL;
	else
	{
		position i,j;
		int n = 0;
		for (i = head; i->next != NULL; i = i->next)
		{
			n++;
			if (n == K)
			{
				j = prevpos(head, i);
				j->next = i->next;
				n = 0;
			}
		}
		return head;
	}
}