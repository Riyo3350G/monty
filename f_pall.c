#include "monty.h"

/**
 * f_pall - Print all values in the stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number in the bytecode file
 *
 * Return: void.
 */
void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *node;

	node = *head;
	while (node != NULL)
	{
		fprintf(stdout,"%d\n", node->n);
		fflush(stdout);
		node = node->next;
	}

	(void)line_number;
}
