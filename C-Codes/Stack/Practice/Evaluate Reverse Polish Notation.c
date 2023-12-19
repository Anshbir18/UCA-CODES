// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack {
    int size;
    int top;
    int* arr;
};

void init_stack(struct Stack* st, int n) {
    st->top = -1;
    st->size = n;
    st->arr = malloc(n * sizeof(int));
}

bool push(struct Stack* st, int ele) {
    if (st->top >= st->size - 1) {
        return false;
    }
    st->top++;
    st->arr[st->top] = ele;
    return true;
}

int pop(struct Stack* st) {
    if (st->top <= -1) {
        return 0; // Assuming 0 is an invalid result for the RPN expression
    }
    int val = st->arr[st->top];
    st->top--;
    return val;
}

int evalRPN(char** tokens, int tokensSize) {
    struct Stack stack;
    init_stack(&stack, tokensSize);

    for (int i = 0; i < tokensSize; i++) {
        if (isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
            // If the token is a number or a negative number
            push(&stack, (tokens[i]-'0'));
        } else {
            // If the token is an operator
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (tokens[i][0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    return 0; // Invalid operator
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}
