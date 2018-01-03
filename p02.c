#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

int GetNth(struct node *head, int n);

int
main(void)
{
	struct node **testcases = get_testcases();
	int i;

	for (i = 0; i < 7; i++) {
		dump(testcases[i]);

		printf("%d\n\n", GetNth(testcases[i], 0));
	}

	return (EXIT_SUCCESS);
}

int
GetNth(struct node *head, int n)
{
	struct node *node;
	int i = 0;

	if (n < 0) {
		abort();
	}

	for (node = head; node != NULL; node = node->next) {
		if (i == n) {
			return (node->data);
		}

		i++;
	}

	abort();
}
