#include "monty.h"
/**
 * free_stack - function that free stack
 * @h: head
 * Return: Nothing
 */

void free_stack(stack_t *h)
{
	stack_t *temp;

	temp = h;
	
	while (h != NULL)
	{
		temp = h->next;
		free(h);
		h = temp;
	}
}