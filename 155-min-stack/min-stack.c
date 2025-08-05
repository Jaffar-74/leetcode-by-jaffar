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