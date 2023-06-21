#include "monty.h"

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char **argv)
{
	FILE *file;
	size_t n = 0;
	ssize_t read = 1;
	stack_t *stack = NULL;
	char *file_data;
	unsigned int line_num = 0;

	/* check arguments count */
	if (argc != 2)
	{
		printf("ERROR\n");
		exit(EXIT_FAILURE);
	}

	/* open and read file data */
	file = fopen(argv[1], "r");
	box.file = file;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read > 0)
	{
		file_data = NULL;
		read = getline(&file_data, &n, file);
		box.data = file_data;
		line_num++;
		if (read > 0)
		{
			exec(file_data, &stack, line_num, file);
		}
		free(file_data);
	}

	free_stack(stack);
	fclose(file);

	return (0);
}