#define _POSIX_C_SOURCE 200809L
#include "monty.h"
container data = {NULL, NULL, NULL, 0};
/**
 * main - Entry point to Interpreter
 * @argc: Number of command line arguments
 * @argv: Array of string arguments passed in commad line
 * Return: 0 on Success
 */

int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t n = 0;
    ssize_t no_read = 1;
    stack_t *stack = NULL;
    unsigned int line_no = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    data.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (no_read > 0)
    {
        content = NULL;
        no_read = getline(&content, &n, file);
        data.content = content;
        line_no++;
        if (no_read > 0)
        {
            executioner(content, &stack, line_no, file);
        }
        free(content);
    }
    __freestack(stack);
    fclose(file);
    return (0);
}
