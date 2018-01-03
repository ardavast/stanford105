#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

static int Count(struct node *head);

int
main(void)
{
	struct node **testcases = get_testcases();
	int i;

	for (i = 0; i < 7; i++) {
		dump(testcases[i]);

		(void)printf("%d\n\n", Count(testcases[i]));
	}

	return (EXIT_SUCCESS);
}

static int
Count(struct node *head)
{
	struct node *node;
	int i = 0;

	for (node = head; node != NULL; node = node->next) {
		i++;
	}

	return (i);
}
