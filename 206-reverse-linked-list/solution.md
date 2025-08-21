# Intuition
The problem is to **reverse a singly linked list**.  
Normally, this is done in-place by adjusting pointers, but here a **stack** is used.  

The stack leverages the **LIFO (Last In First Out)** property:
- Push nodes one by one → they get stored in original order.  
- Pop them → they come out in reverse order.  

So, popping and re-linking nodes gives a reversed linked list.

# Approach
**Create a stack** to hold node addresses (`struct ListNode*`).
2. **Traverse the list** and push each node onto the stack.
3. **Pop nodes** one by one from the stack, re-linking them:
   - The first popped node becomes the new `head`.
   - Keep popping until stack is empty, attaching each node as `next`.
4. **Terminate the list** by setting the last node’s `next = NULL`.

# Complexity
**Time Complexity:**
  - Traversal to push all nodes → **O(n)**  
  - Traversal to pop all nodes → **O(n)**  
  - ✅ Overall: **O(n)**

**Space Complexity:**
  - Stack stores all `n` nodes → **O(n)**  
  - ✅ Additional memory beyond input list is proportional to list length.


# Code
```c []
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

```
