#include "monty.h"

/**
 * free_stack - Free all nodes in the stack
 * @stack: Pointer to the head of the stack
 *
 * Return: void.
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
