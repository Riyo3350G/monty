#include "monty.h"
/**
 * f_add - adds new elements at the top of the stack.
 * @head: head
 * @line_number: line number
 * Return: Nothing
*/
void f_add(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(global.file);
		free(global.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->n + (*head)->next->n;
	(*head)->next->n = temp;
	original_head = *head;
	*head = (*head)->next;
	free(original_head);
}

