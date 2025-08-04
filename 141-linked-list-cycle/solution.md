## Intuition
If there's a cycle in a linked list, a fast-moving pointer will eventually "lap" a slow-moving pointer.  
This is similar to two runners on a circular track — if there's a loop, they'll meet; if not, the fast runner will reach the end.

## Approach
Use two pointers:
- `slow` moves one step at a time
- `fast` moves two steps at a time

If at any point `slow == fast`, a cycle is detected.  
If `fast` reaches the end (`NULL`), the list has no cycle.

## Complexity

- **Time complexity:** `O(n)`  
  In the worst case, the fast pointer traverses all nodes before either finding a cycle or reaching the end.

- **Space complexity:** `O(1)`  
  No extra space is used — only two pointers are maintained.

## Code
```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;  // cycle detected
        }
    }
    return false;  // no cycle
}
