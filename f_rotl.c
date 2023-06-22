#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void f_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *top_element = *head;
	stack_t *second_top = *head;

	if (top_element == NULL || top_element->next == NULL)
		return;

	while (second_top->next != NULL)
		second_top = second_top->next;

	*head = top_element->next;
	(*head)->prev = NULL;
	second_top->next = top_element;
	top_element->prev = second_top;
	top_element->next = NULL;

	(void)line_number;
}
