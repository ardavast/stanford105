#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

void SortedInsert(struct node **head, struct node *new_node);
void InsertSort(struct node **head);

int
main(void)
{
	struct node **testcases = get_testcases();
	int i;

	for (i = 0; i < 7; i++) {
		dump(testcases[i]);

		InsertSort(&testcases[i]);

		dump(testcases[i]);

		(void)puts("");
	}

	return (EXIT_SUCCESS);
}

void
SortedInsert(struct node **head, struct node *new_node)
{
	struct node **node;

	for (node = head; *node != NULL; node = &((*node)->next)) {
		if (new_node->data <= (*node)->data )
			break;
	}

	new_node->next = *node;
	*node = new_node;
}

void
InsertSort(struct node **head)
{
        struct node *new_head = NULL;
	struct node *new_node;
	struct node *node, *snode;

	node = *head;
	while (node != NULL) {
		new_node = malloc(sizeof(struct node));
		new_node->data = node->data;
		SortedInsert(&new_head, new_node);
		snode = node;
		node = node->next;
		free(snode);
	}

	*head = new_head;
}
