#include "monty.h"

/**
 * get_op_func - Searches for an opcode and returns its corresponding function.
 * @opcode: The opcode to search for.
 *
 * Return: Pointer to the corresponding function if found, NULL otherwise.
 */
void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
    instruction_t instructions[] = {
        {"push", monty_push},
        {"pall", monty_pall},
        /* Add other opcodes here as needed */
        {NULL, NULL}
    };

    int i = 0;
    while (instructions[i].opcode != NULL)
    {
        if (strcmp(instructions[i].opcode, opcode) == 0)
            return (instructions[i].f);
        i++;
    }

    return (NULL);
}

