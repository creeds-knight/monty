#include "monty.h"

/**
 * __pall - A function to print the stack
 * @head: A pointer to head of stack
 * @line_no: Current line number
 */

void __pall(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	(void)line_no;

	tmp = *head;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
