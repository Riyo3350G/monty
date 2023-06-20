#include <stdio.h>
#include "monty.h"

global_t global;

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
