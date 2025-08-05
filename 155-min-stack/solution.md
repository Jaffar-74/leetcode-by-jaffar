# Intuition
To design a stack that supports `push`, `pop`, `top`, and `getMin` operations in **constant time**, we need an auxiliary structure to track the **minimum value** at each stage of the stack.


# Approach
We use **two stacks**:
- `stack[]`: Stores all pushed values.
- `minStack[]`: Keeps track of the current minimum values.

**Push operation**:
- Push the value to `stack`.
- Push to `minStack` **only if** it is smaller than or equal to the current minimum.

**Pop operation**:
- If the value being popped from `stack` is equal to the top of `minStack`, also pop from `minStack`.

This ensures:
- `top()` returns the top of `stack`.
- `getMin()` returns the top of `minStack`, which always holds the current minimum.

# Complexity
### Time complexity:
- `push()`: O(1)
- `pop()`: O(1)
- `top()`: O(1)
- `getMin()`: O(1)

### Space complexity:
- O(n): In the worst case (e.g., descending order), all elements may be added to both `stack` and `minStack`.

# Code
```c []
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ARR_SIZE 10000  // Increase size to handle large test cases

typedef struct {
    int stack[ARR_SIZE];
    int minStack[ARR_SIZE];
    int top;
    int minTop;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    obj->minTop = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++(obj->top)] = val;

    if (obj->minTop == -1 || val <= obj->minStack[obj->minTop]) {
        obj->minStack[++(obj->minTop)] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top == -1) return;

    if (obj->stack[obj->top] == obj->minStack[obj->minTop]) {
        obj->minTop--;
    }
    obj->top--;
}

int minStackTop(MinStack* obj) {
    if (obj->top == -1) return -1;
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    if (obj->minTop == -1) return -1;
    return obj->minStack[obj->minTop];
}

void minStackFree(MinStack* obj) {
    free(obj);
}



/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
```
