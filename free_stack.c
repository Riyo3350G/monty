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

	current = stack;

	while (stack != NULL)
	{
		current = stack->next;
		free(stack);
		stack = current;
	}
}
