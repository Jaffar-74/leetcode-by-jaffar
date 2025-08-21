/**
 * Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
    };
 */



#define ARR_Size 5000

typedef struct {
    struct ListNode* stack[ARR_Size];
    int top;
} Stack;

Stack* createstack() {
    Stack* obj = (Stack*)malloc(sizeof(Stack));
    obj->top = -1;
    return obj;
}

void stackpush(Stack* obj, struct ListNode* node) {
    if (obj->top >= ARR_Size - 1) {
        printf("Stack overflow!\n");
        return;
    }
    obj->stack[++obj->top] = node;
}

struct ListNode* stackpop(Stack* obj) {
    if (obj->top == -1) {
        printf("Stack underflow!\n");
        return NULL;
    }
    return obj->stack[obj->top--];
}

struct ListNode* reverseList(struct ListNode* head) {
    if (!head) return NULL;

    Stack* obj = createstack();
    struct ListNode* curr = head;

    // Push all nodes into stack
    while (curr) {
        stackpush(obj, curr);
        curr = curr->next;
    }

    // Pop to rebuild reversed list
    head = stackpop(obj);
    curr = head;
    while (obj->top != -1) {
        curr->next = stackpop(obj);
        curr = curr->next;
    }
    curr->next = NULL;  // terminate reversed list

    return head;
}
