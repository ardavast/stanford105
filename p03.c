#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

void Delete(struct node **head);

int
main(void)
{
	struct node **testcases = get_testcases();
	int i;

	for (i = 0; i < 7; i++) {
		dump(testcases[i]);

		Delete(&testcases[i]);
		dump(testcases[i]);

		puts("");
	}

	return (EXIT_SUCCESS);
}

void
Delete(struct node **head)
{
	struct node *node;

	for (node = *head; node != NULL; node = node->next) {
		free(node);
	}

	*head = NULL;
}
