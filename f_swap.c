#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void f_swap(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	original_head = *head;
	temp = original_head->n;
	original_head->n = original_head->next->n;
	original_head->next->n = temp;
}
