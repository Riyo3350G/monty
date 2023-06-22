#include "monty.h"

int main(int argc, char *argv[]);
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
		fflush(stdout);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.file = fopen(argv[1], "r");

	if (global.file == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	call_op(&node);
	fclose(global.file);
	free(global.line);
	free_stack(node);
	exit(EXIT_SUCCESS);
}
