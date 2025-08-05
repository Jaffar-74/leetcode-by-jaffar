## Intuition
If you move one pointer twice as fast as the other, by the time the faster pointer reaches the end, the slower pointer will be at the middle.

This is similar to two people running on a track — if one runs at double the speed, they'll complete the distance while the slower runner reaches halfway.

## Approach
Use two pointers:
- `slow`: moves one step at a time.
- `fast`: moves two steps at a time.

Loop through the list until `fast` reaches the end:
- When the loop ends, `slow` will be pointing at the **middle node**.

This method works for both:
- **Odd-length** lists (returns the exact middle)
- **Even-length** lists (returns the second middle)
  
## Complexity
### Time Complexity
- O(n): We traverse the list once.

### Space Complexity
- O(1): Only two pointers are used regardless of the list size.

# Code
```c []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
return slow;
}
```
