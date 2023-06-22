i#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom.
 * @head: Double pointer to the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void f_rotr(stack_t **head, unsigned int line_number)
{
	if (*head == NULL || (*head)->next == NULL)
		return;

	stack_t *last_element = *head;

	while (last_element->next != NULL)
		last_element = last_element->next;

	last_element->prev->next = NULL;
	last_element->next = *head;
	last_element->prev = NULL;
	(*head)->prev = last_element;
	*head = last_element;
	(void)line_number;
}
