#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char* arr;
    int top;
    int capacity;
} Minstack;

Minstack* Minstack_create(int capacity) {
    Minstack* stack = (Minstack*)malloc(sizeof(Minstack));
    if (!stack) return NULL;
    stack->arr = (char*)malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

bool isValid(char* s) {
    int len = strlen(s);
    Minstack* stack = Minstack_create(len);
    if (!stack) return false;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack->arr[++stack->top] = c;
        } else {
            if (stack->top == -1) return false;
            char topChar = stack->arr[stack->top--];
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    bool isEmpty = (stack->top == -1);
    free(stack->arr);
    free(stack);
    return isEmpty;
}