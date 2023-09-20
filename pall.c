#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int stack[STACK_SIZE];
int top = -1;
int line_number = 0;

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}
int i;
void pall() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    
   
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
