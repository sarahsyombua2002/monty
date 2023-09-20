#include "monty.h"

void monty_pall(stack_t **stack, unsigned int line_number);

/**
 * monty_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current_node = (*stack)->next;

    while (current_node)
    {
        printf("%d\n", current_node->n);
        current_node = current_node->next;
    }
    (void)line_number;
}
