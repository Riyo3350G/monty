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

	if (global.arg == NULL || !_isdigit(global.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fflush(stderr);
		free_stack(*head);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fflush(stderr);
		free_stack(*head);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}

	node->n = atoi(global.arg);

	if (*head == NULL)
	{
		(*head) = node;
		node->prev = NULL;
		node->next = NULL;
	}
	else
	{
		(*head)->prev = node;
		node->next = *head;
		(*head) = node;
	}
}


/**
 * _isdigit - checks if parameter is a number between 0 to 9.
 * @c: character.
 * Return: 1 if is a number (0 to 9), 0 in other case.
 */
int _isdigit(char *c)
{
	if (*c >= 48 && *c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
