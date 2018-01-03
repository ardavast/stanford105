#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

int Pop(struct node **head);

int
main(void)
{
	struct node **testcases = get_testcases();
	int data;
	int i;

	for (i = 0; i < 7; i++) {
		dump(testcases[i]);

		data = Pop(&testcases[i]);
		dump(testcases[i]);
		printf("data = %d\n\n", data);
	}

	return (EXIT_SUCCESS);
}

int
Pop(struct node **head)
{
	struct node *node;
	int data;

	if (*head == NULL) {
		abort();
	}

	node = *head;
	*head = (*head)->next;
	data = node->data;
	free(node);

	return (data);
}
