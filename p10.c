#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "test.h"

void SortedInsert(struct node **head, struct node *new_node);
void InsertSort(struct node **head);
void RemoveDuplicates(struct node *head);

int
main(void)
{
	struct node **testcases = get_testcases();
	int i;

	for (i = 0; i < 7; i++) {
		dump(testcases[i]);

		InsertSort(&testcases[i]);
		RemoveDuplicates(testcases[i]);

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
	struct node *node, *prev_node;

	node = *head;
	while (node != NULL) {
		new_node = malloc(sizeof(struct node));
		new_node->data = node->data;
		SortedInsert(&new_head, new_node);
		prev_node = node;
		node = node->next;
		free(prev_node);
	}

	*head = new_head;
}

void RemoveDuplicates(struct node *head)
{
	struct node *node, *nextnode, *snextnode;

	if (head == NULL || head->next == NULL)
		return;

	node = head;
	nextnode = node->next;
	while (node != NULL) {
		nextnode = node->next;
	        while (nextnode != NULL && nextnode->data == node->data) {
			snextnode = nextnode;
	             	nextnode = nextnode->next;
			free(snextnode);
		}
		node->next = nextnode;
		node = node->next;
	}
}
