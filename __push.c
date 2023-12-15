#include "monty.h"
/**
 * __push - A function to add a node to the stack
 * @head: A pointer to the pointer to head of the stack
 * @line_no: Current line number
 * Return: No value returned
 */
void __push(stack_t **head, unsigned int line_no)
{
    int m, i = 0, flagg = 0;

    if (data.arg)
    {
        if (data.arg[0] == '-')
            i++;
        for (; data.arg[i] != '\0'; i++)
        {
            if(data.arg[i] > 57 || data.arg[i] < 48)
                flagg = 1;
        }
        if (flagg == 1)
        {
            fprintf(stderr, "L%d: Usage: push interger\n", line_no);
            fclose(data.file);
            free(data.content);
            __freestack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer \n", line_no);
        fclose(data.file);
        free(data.content);
        __freestack(*head);
        exit(EXIT_FAILURE);
    }
    m = atoi(data.arg);
    if (data.stk_or_que == 0)
        add_node(head, m);
    else
        add_queue(head, m);
}

