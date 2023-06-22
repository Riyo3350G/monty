#include "monty.h"

/**
 * f_pop - Removes the top element from the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *node;

	node = *head;

	if (*head == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*head = (*head)->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(node);
	(void)line_number;
}
