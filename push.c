#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);

/**
 * monty_push - Pushes a value onto a stack_t linked list.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node, *temp;
    int i;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        set_op_tok_error(malloc_error());
        return;
    }

    if (op_toks[1] == NULL)
    {
        set_op_tok_error(no_int_error(line_number));
        return;
	 }

    for (i = 0; op_toks[1][i]; i++)
    {
        if (op_toks[1][i] == '-' && i == 0)
            continue;
        if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
        {
            set_op_tok_error(no_int_error(line_number));
            return;
        }
    }
    new_node->n = atoi(op_toks[1]);
     if (check_mode(*stack) == STACK) /* STACK mode, insert at the front */
    {
        temp = (*stack)->next;
        new_node->prev = *stack;
        new_node->next = temp;
        if (temp)
            temp->prev = new_node;
        (*stack)->next = new_node;
    }
    else /* QUEUE mode, insert at the end */
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        new_node->prev = temp;
        new_node->next = NULL;
        temp->next = new_node;
    }
  }
