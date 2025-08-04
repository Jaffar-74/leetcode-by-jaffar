# Intuition
To check if parentheses are valid, we must ensure that every opening bracket has a corresponding closing one in the correct order.
This is a classic stack problem, where we push opening brackets and pop them only when we encounter a matching closing one.

# Approach
**1.** Traverse the string character by character.

**2.** Push opening brackets `(`,`{`, `[` onto a custom stack.

**3.** On encountering a closing bracket, pop from the stack and check if it matches the current character.

**4.** If the stack is empty at the end, the string is valid; otherwise, it's not.



# Complexity
- **Time complexity:** `O(n)`
Each character is processed once — either pushed or popped.

- **Space complexity:** `O(n)`
In the worst case (for example., all opening brackets), the stack can grow to size n.

# Code
```c []
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

```
