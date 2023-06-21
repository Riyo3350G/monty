#include "monty.h"
/**
 * f_add - adds new elements at the top of the stack.
 * @h: head
 * @line_num: line number
 * Return: Nothing
*/
void f_add(stack_t **h, unsigned int line_num)
{
	stack_t *temp;
	int count = 0;
	int data;

	temp = *h;
	while (h)
	{
		temp = temp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(global.file);
		free(global.line);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	temp = *h;
	data = temp->n + temp->next->n;
	temp->next->n = data;
	*h = temp->next;
	free(temp);
}
