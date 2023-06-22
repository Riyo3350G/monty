#include "monty.h"

/**
 * f_pint - Prints the value of the top element of a stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number counter
 */
void f_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(global.file);
		free(global.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
