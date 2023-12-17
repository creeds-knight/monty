#include "monty.h"
/**
 * __pchar - A function to print a character at the top of the stack
 * @head: Pointer to head of stack
 * @line_no: The current line number
 * Return: None
 */
void __pchar(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		fclose(data.file);
		free(data.file);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	if (tmp->n >127 || tmp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		fclose(data.file);
		free(data.file);
		__freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}
/**
 * __pstr - A function to print the string at the top of the stack
 * @head: The pointer to head of the stack
 * @line_no: Current line number
 * Return: None
 */
void __pstr(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	(void) line_no;

	tmp = *head;
	while (tmp)
	{
		if (tmp->n > 127 || tmp->n <= 0)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * __rotl - A function to rotate the stack to the top
 * @head: A pointer to head of the stack
 * @line_no: Current line number
 * Return: None
 */
void __rotl(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	stack_t *mm;
	(void) line_no;

	tmp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	mm = (*head)->next;
	mm->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = mm;
}
/**
 * __rotr - A function to rotate the stack to the bottom
 * @head: A pointer to head of the stack
 * @line_no: Current line number
 * Return: None
 */
void __rotr(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	(void) line_no;

	tmp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	(*head) = tmp;
}
