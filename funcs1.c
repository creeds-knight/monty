#include "monty.h"
/**
 * __pint - A function to print the top of the stack
 * @head: The pointer to the head of the stack
 * @line_no: The Current line number
 * Return: NOne
 */
void __pint(stack_t **head, unsigned int line_no)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * __pop - A function to print the top of the stack or queue
 * @head:  Pointer to head of the stack
 * @line_no: Line number
 * Return: NOne
 */

void __pop(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop empty stack\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = tmp->next;
	free(tmp);
}
/**
 * __swap - A function to swap the top two elements of a stack
 * @head: A pointer to the head of the lisr
 * @line_no: Line number
 * Return: None
 */
void __swap(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	int n = 0;
	int m;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	m = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = m;
}
/**
 * __add - A function to add the top two elements
 * @head: A pointer to the head of the stack
 * @line_no: Current line number in the file
 * Return: None
 */
void __add(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	int n = 0;
	int m;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	if (n < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	m = tmp->n + tmp->next->n;
	tmp->next->n = m;
	*head = tmp->next;
	free(tmp);
}
/**
 * __nop - A function that returns nothing
 * @head: A pointer to the head of the stack
 * @line_no: Current line number in the file
 * Return: None
 */
void __nop(stack_t **head, unsigned int line_no)
{
	(void) line_no;
	(void) head;
}
