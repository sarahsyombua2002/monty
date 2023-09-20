#include "monty.h"

void monty_pint(stack_t **stack, unsigned int line_number);

/**
 * monty_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
    if (stack == NULL || *stack == NULL ||(*stack)->next == NULL)
    {
        set_op_tok_error(pint_error(line_number));
        return;
    }

    printf("%d\n", (*stack)->next->n);
}
