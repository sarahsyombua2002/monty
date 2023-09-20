#include "monty.h"

void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(line_number, "swap"));
        return;
    }
 temp = (*stack)->next->next;
    (*stack)->next->next = temp->next;
    (*stack)->next->prev = temp;
    if (temp->next)
        temp->next->prev = (*stack)->next;
    temp->next = (*stack)->next;
    temp->prev = *stack;
    (*stack)->next = temp;
}
