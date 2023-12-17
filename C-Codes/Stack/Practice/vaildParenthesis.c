#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    char* arr;
};

void init_stack(struct Stack* st, int n) {
    st->top = -1;
    st->size = n;
    st->arr = malloc(n * sizeof(char));
}

bool push(struct Stack* st, char ele) {
    if (st->top >= st->size - 1) {
        return false;
    }
    st->top++;
    st->arr[st->top] = ele;
    return true;
}

char pop(struct Stack* st) {
    if (st->top <= -1) {
        return '0';
    }
    char ch = st->arr[st->top];
    st->top--;
    return ch;
}

char peek(struct Stack* st) {
    if (st->top <= -1) {
        return '0';
    }
    char ch = st->arr[st->top];
    return ch;
}

bool empty(struct Stack* st) {
    return st->top == -1;
}


bool isValid(char* s) {
    struct Stack st;
    int n=strlen(s);
    init_stack(&st,n);


    for(int i=0;i<n;i++){
        if(s[i]=='(' || s[i]=='{'||s[i]=='['){
            push(&st,s[i]);
        }
        else{
            if(empty(&st)){
                return false;
            }
            else{
                if(peek(&st)=='[' && s[i]==']'){
                    pop(&st);
                }
                else if(peek(&st)=='(' && s[i]==')'){
                    pop(&st);
                }
                else if(peek(&st)=='{' && s[i]=='}'){
                    pop(&st);
                }
                else{
                    return false;
                }
            }
        }
    }

    if(empty(&st)){
        return true;
    }
    return false;

}
