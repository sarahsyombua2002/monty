#include "monty.h"

void monty_pop(stack_t **stack, unsigned int line_number);

/**
 * monty_pop - Removes the top value element from a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *next_node = NULL;

    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pop_error(line_number));
        return;
    }
     next_node = (*stack)->next->next;
    free((*stack)->next);
    if (next_node)
        next_node->prev = *stack;
    (*stack)->next = next_node;
}
