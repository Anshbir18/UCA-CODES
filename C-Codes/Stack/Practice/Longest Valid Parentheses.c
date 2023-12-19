// https://leetcode.com/problems/longest-valid-parentheses/description/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct stack {
    int size;
    int top;
    int* arr;
};

void init_stack(struct stack* st, int n) {
    st->arr = malloc((n + 1) * sizeof(int)); 
    st->top = -1;  
    st->size = n + 1;  
}

void free_stack(struct stack* st) {
    free(st->arr);
}

void push(struct stack* st, int ele) {
    if (st->top >= st->size) {
        return;
    }
    st->top++;
    st->arr[st->top] = ele;
}

void pop(struct stack* st) {
    if (st->top <= -1) {
        return; 
    }
    st->top--;
}

int peek(struct stack* st) {
    if (st->top <= -1) {
        return -1;
    }
    int x = st->arr[st->top];
    return x;
}

bool empty(struct stack* st) {
    return st->top == -1;
}

int longestValidParentheses(char* s) {
    struct stack st;
    int len = strlen(s);
    int max_len = 0;
    init_stack(&st, len);
    push(&st, -1);

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            push(&st, i);
        } else {
            pop(&st);

            if (empty(&st)) {
                push(&st, i);
            } else {
                int x = peek(&st);
                int temp_len = i - x;

                if (temp_len > max_len) {
                    max_len = temp_len;
                }
            }
        }
    }

    

    return max_len;
}

