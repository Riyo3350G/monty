#include "monty.h"

/**
 * call_op - Call operations based on bytecodes
 * @stack: Pointer to the stack
 *
 * Return: void.
 */
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

/**
 * exec_op - Execute operation based on opcode
 * @opcode: Opcode to be executed
 * @stack: Pointer to the stack
 * @line_number: Line number in the bytecode file
 *
 * Return: void.
 */
void exec_op(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t inst[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
<<<<<<< HEAD
		{"add", f_add},
=======
		{"swap", f_swap},
>>>>>>> 5b8c0a843431d5ab6bb976adb18f3fdc95aeecec
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
