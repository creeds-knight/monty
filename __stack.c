#include "monty.h"
/**
 * __stack - Starting the stack
 * @head: stack head
 * @line_no: Current number of the line
 * Return: no return
 */

void __stack(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;
	data.stk_or_que = 0;
}

/**
 * add_node - A function to add the node to a stack
 * @head: The pointer to the head of the stack
 * @n: data to be added to the new node
 * Return: none
 */

void add_node(stack_t **head, int n)
{
	stack_t *newnode, *tmp;

	tmp = *head;
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		perror("Malloc Error");
		exit(0);
	}
	if (tmp)
		tmp->prev = newnode;
	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;
}

/**
 * __freestack - a function to free the list
 * @head: A pointer to head of stack
 */

void __freestack(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
