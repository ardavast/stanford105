#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

void SortedInsert(struct node **head, struct node *new_node);

int
main(void)
{
	struct node **testcases = get_testcases();
	struct node *new_node;
	int i;

	for (i = 0; i < 7; i++) {
		new_node = malloc(sizeof(struct node));
		new_node->data = 10;
		new_node->next = NULL;

		dump(testcases[i]);

		SortedInsert(&testcases[i], new_node);
		dump(testcases[i]);

		puts("");
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
