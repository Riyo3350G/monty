#include "monty.h"

/**
 * f_pstr - Prints the string starting from the top of the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void f_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *node = *head;

	while (node != NULL && node->n != 0)
	{
		if (node->n >= 0 && node->n <= 127)
		{
			printf("%c", current->n);
			current = current->next;
		}
	}

	printf("\n");
	(void)line_number;
}
