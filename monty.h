#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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

/* OPCODE FUNCTIONS */
void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *str, char *delims);
char *get_int(int n);

/* PRIMARY INTERPRETER FUNCTIONS */
void free_tokens(void);
int run_monty(FILE *script_fd);
void set_op_tok_error(int error_code);

/* ERROR MESSAGES & ERROR CODES */
int usage_error(void);
int f_open_error(char *filename);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int malloc_error(void);
int no_int_error(unsigned int line_number);
int check_mode(stack_t *stack);
int pop_error(unsigned int line_number);

/*Additional */
void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int unknown_op_error(char *opcode, unsigned int line_number);
unsigned int token_arr_len(void);

#endif /* MONTY_H */


