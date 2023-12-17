#include "monty.h"
/**
 * __sub - A function to subtract the top two elements
 * @head: A pointer to the head of the stack
 * @line_no: Current line number in the file
 * Return: None
 */
void __sub(stack_t **head, unsigned int line_no)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	m = tmp->next->n - tmp->n;
	tmp->next->n = m;
	*head = tmp->next;
	free(tmp);
}
/**
 * __div - A function to divide the last two elements
 * @head: The pointer to the head of the stack
 * @line_no: Current line number
 * Return: NOne
 */
void __div(stack_t **head, unsigned int line_no)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}m = tmp->n / tmp->next->n;
	tmp->next->n = m;
	*head = tmp->next;
	free(tmp);
}
/**
 * __mul - A function to multiply the top two elements
 * @head: A pointer to the head of the stack
 * @line_no: Current line number in the file
 * Return: None
 */
void __mul(stack_t **head, unsigned int line_no)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	m = tmp->n * tmp->next->n;
	tmp->next->n = m;
	*head = tmp->next;
	free(tmp);
}
/**
 * __mod - A function to find the modulus of the top two elements
 * @head: A pointer to the head of the stack
 * @line_no: Current line number in the file
 * Return: None
 */
void __mod(stack_t **head, unsigned int line_no)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		fclose(data.file);
		free(data.content);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	m = tmp->next->n % tmp->n;
	tmp->next->n = m;
	*head = tmp->next;
	free(tmp);
}
