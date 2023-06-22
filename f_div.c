#include "monty.h"

/**
 * f_div - Divides the second top element of the stack by the top element.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void f_div(stack_t **head, unsigned int line_number)
{
	stack_t *original_head;
	unsigned int len = 0, temp;

	original_head = *head;

	while (original_head != NULL)
	{
		len++;
		original_head = original_head->next;
	}
	if (len < 2)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(global.file);
		free(global.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next->n / (*head)->n;
	(*head)->next->n = temp;
	original_head = *head;
	*head = (*head)->next;
	free(original_head);
}
