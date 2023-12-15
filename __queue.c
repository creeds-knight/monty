#include "monty.h"
/**
 * __queue - A function to set the queue flag and display the queue
 * @head: A pointer to keep track of the head
 * @line_no: Current line number
 * Return: none
 */

void __queue(stack_t **head, unsigned int line_no)
{
    (void)head;
    (void)line_no;
    data.stk_or_que = 1;
}
/**
 * add_queue - A function to add a node to the tail of the queue
 * @n: data to be added in the new node
 * @head: Head of the stack
 * Return: no return
 */

void add_queue(stack_t **head, int n)
{
    stack_t *newnode, *tmp;

    tmp = *head;
    newnode = malloc(sizeof(stack_t));
    if (newnode == NULL)
    {
        perror("Malloc Error\n");
    }
    newnode->n = n;
    newnode->next = NULL;
    if (tmp)
    {
        while (tmp->next)
            tmp = tmp->next;
    }
    if (!tmp)
    {
        *head = newnode;
        newnode->prev = NULL;
    }
    else
    {
        tmp->next = newnode;
        newnode->prev = tmp;
    }
}
