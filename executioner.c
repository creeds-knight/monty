#include "monty.h"
/**
 * exe - A function that executes the opcode
 * @stack: The pointer to the head of the linked list
 * @line_no: Current number of line
 * @file : A pointer to the monty file
 * @content: Line data
 * Return: 0 on Success
 */

int exe(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
	instruction_t opdata[] = {{"push", __push}, {"pall", __pall},
	{"pint", __pint},
	{"pop", __pop},
	{"swap", __swap},
	{"add", __add},
	{"sub", __sub},
	{"div", __div},
	{"mul", __mul},
	{"mod", __mod},
	{"nop", __nop}};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	data.arg = strtok(NULL, " \n\t");
	while (opdata[i].opcode && op)
	{
		if (strcmp(op, opdata[i].opcode) == 0)
		{
			opdata[i].f(stack, line_no);
			return (0);
		}
		i++;
	}
	if (op && opdata[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op);
		fclose(file);
		free(content);
		__freestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
