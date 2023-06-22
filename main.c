#include "monty.h"

void f_nop(stack_t **head, unsigned int line_number);
global_t global = {NULL, NULL, NULL, 0};

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: On succes (0).
 */
int main(int argc, char *argv[])
{
	stack_t *node = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.file = fopen(argv[1], "r");

	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	call_op(&node);
	fclose(global.file);
	free(global.line);
	free_stack(node);
	exit(EXIT_SUCCESS);
}

/**
 * f_nop - do nothing
 * @head: head
 * @line_number: line number
 * Return: void.
 */
void f_nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
