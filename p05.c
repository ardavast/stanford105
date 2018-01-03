#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

void InsertNth(struct node **head, int n, int data);

int
main(void)
{
	struct node **testcases = get_testcases();
	int i;

	for (i = 0; i < 7; i++) {
		dump(testcases[i]);

		InsertNth(&testcases[i], 0, 10);
		dump(testcases[i]);

		InsertNth(&testcases[i], 1, 12);
		dump(testcases[i]);

		InsertNth(&testcases[i], 1, 11);
		dump(testcases[i]);

		puts("");
	}

	return (EXIT_SUCCESS);
}

void
InsertNth(struct node **head, int n, int data)
{
	struct node **node, *new_node;
	int i = 0;

	for (node = head; *node != NULL; node = &((*node)->next)) {
		if (i == n)
			break;
		i++;
	}

	if (i < n) {
		abort();
	}

	new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = *node;
	*node = new_node;
}
