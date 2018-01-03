#include <stdio.h>
#include <stdlib.h>

#include "node.h"

static void append(struct node **head, int data);
void dump(struct node *head);

struct node **
get_testcases(void)
{
	int tc0[] = {7, -1, 0, 1, 2, 3, 4, 5};
	int tc1[] = {7, 5, 4, 3, 2, 1, 0, -1};
	int tc2[] = {7, 4, -1, 0, 5, 2, 3, 1};
	int tc3[] = {4, 1, 1, 2, 3};
	int tc4[] = {12, 1, 1, 1, 1, 3, 3, 3, 4, 4, 4, 4, 4};
	int tc5[] = {1, 10};
	int tc6[] = {0};
	int *tcs[] = {tc0, tc1, tc2, tc3, tc4, tc5, tc6};
	int ntcs = sizeof(tcs) / sizeof(tcs[0]);

	struct node **testcases;
	int *tc;
	int tc_size;
	int i, j;

	testcases = malloc(sizeof(struct node *) * ntcs);
	for (i = 0; i < ntcs; i++) {
		tc = tcs[i];
		tc_size = tc[0];
		testcases[i] = NULL;
	        for (j = 0; j < tc_size; j++) {
			append(&testcases[i], (tc[j + 1]));
		}
	}

	return (testcases);
}

static void
append(struct node **head, int data)
{
	struct node **tail;

    	for (tail = head; *tail != NULL; tail = &((*tail)->next))
			;

	*tail = malloc(sizeof(struct node));
	(*tail)->data = data;
	(*tail)->next = NULL;
}

void
dump(struct node *head)
{
	struct node *node;

	printf("testcase: ");

    	for (node = head; node != NULL; node = node->next) {
		if (node->next != NULL) {
			printf("%d ", node->data);
		} else {
			printf("%d", node->data);
		}
	}

	puts("");
}
