#include "monty.h"

void f_push(stack_t **head, unsigned int line_number)
{
	stack_t *node;
	node = malloc(sizeof(stack_t));

	if (global.arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*head);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
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
