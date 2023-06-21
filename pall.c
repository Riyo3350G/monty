#include "monty.h"

void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *node;
	node = *head;

	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}

	(void)line_number;
}