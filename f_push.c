#include "monty.h"

/**
 * f_push - Push a value into the stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number in the bytecode file
 *
 * Return: void.
 */
void f_push(stack_t **head, unsigned int line_number)
{
	stack_t *node;

	if (global.arg[0] == '\0' || atoi(global.arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*head);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*head);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}

	node->n = atoi(global.arg);
	node->prev = NULL;
	node->next = *head;

	if (*head != NULL)
		(*head)->prev = node;

	*head = node;
}
