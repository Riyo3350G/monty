#include "monty.h"

void call_op(stack_t **stack)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t ctr;
	unsigned int line_number = 0;

	while ((ctr = getline(&global.line, &len, global.file)) != -1)
	{
		line_number++;
		opcode = strtok(global.line, " \n\t\r\a");
		global.arg = strtok(NULL, " \n\t");
		exec_op(opcode, stack, line_number);	
	}
}

void exec_op(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t inst[] = { 
		{"push", f_push},
		{"pall", f_pall},
		{NULL, NULL}
	};
	
	int i;
	
	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (strcmp(inst[i].opcode, opcode) == 0)
		{
			inst[i].f(stack, line_number);
			return;
		}
	}
	
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	fclose(global.file);
	free(global.line);
	exit(EXIT_FAILURE);
}
