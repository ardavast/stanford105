#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

void Append(struct node **head0, struct node **head1);

int
main(void)
{
	struct node **testcases = get_testcases();
	int i;

	for (i = 0; i < 6; i++) {
		dump(testcases[i]);
		dump(testcases[i + 1]);

		Append(&testcases[i], &testcases[i + 1]);
		dump(testcases[i]);

		puts("");
	}

	return (EXIT_SUCCESS);
}

void Append(struct node **head0, struct node **head1)
{
	struct node *node;

	if (*head0 == NULL) {
		*head0 = *head1;
		return;
	}

	for (node = *head0; node->next != NULL; node = node->next)
		;

	node->next = *head1;
	*head1 = NULL;
}
