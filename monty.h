#ifndef MONTY_H
#define MONTY_H

/** C inbuilt libraries**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#define _POSIX_C_SOURCE 200809L


/**
 * struct stack_s - doubly linked list representationof a stack (or ques)
 * @n: integer
 * @prev: points to previous element in a stack or queue
 * @next: points to the next element in a stack or queue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct container - Variables
 * @file: the pointer to monty file
 * @arg: Value
 * @content: All the content from a particular line in the file
 * @stk_or_que: A flag to change between the stack or the queue
 *
 * Description : Contains  variables to be used
 */
typedef struct container
{
	char *arg;
	FILE *file;
	char *content;
	int stk_or_que;
} container;
extern container data;

/** defined functions*/
void __stack(stack_t **head, unsigned int line_no);
void __queue(stack_t **head, unsigned int line_no);
void add_queue(stack_t **head, int n);
void add_node(stack_t **head, int n);
int exe(char *content, stack_t **stack, unsigned int line_no, FILE *file);
void __push(stack_t **head, unsigned int line_no);
void __pall(stack_t **head, unsigned int line_no);
void __freestack(stack_t *head);
void __pint(stack_t **head, unsigned int line_no);
void __pop(stack_t **head, unsigned int line_no);
void __swap(stack_t **head, unsigned int line_no);
void __add(stack_t **head, unsigned int line_no);
void __nop(stack_t **head, unsigned int line_no);
#endif
