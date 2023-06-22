#include "monty.h"

/**
 * f_pchar - Prints the character at the top of the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void f_pchar(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fflush(stdout);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n < 0 || (*head)->n > 127)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*head)->n);
}

