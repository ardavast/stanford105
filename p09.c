#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

void FrontBackSplit(struct node *head, struct node **front, struct node **back);

int
main(void)
{
	struct node **testcases = get_testcases();
	struct node *front, *back;
	int i;

	for (i = 0; i < 7; i++) {
		dump(testcases[i]);

		FrontBackSplit(testcases[i], &front, &back);
		dump(front);
		dump(back);

		puts("");
	}

	return (EXIT_SUCCESS);
}

void
FrontBackSplit(struct node *head, struct node **front, struct node **back)
{
	struct node *fastp = head;
	struct node **slowp = &head;

	while (fastp != NULL) {
		slowp = &((*slowp)->next);
		fastp = fastp->next;
		if (fastp != NULL)
		    fastp = fastp->next;
	}

	*front = head;
	*back = *slowp;
	*slowp = NULL;
}
