# Intuition
The minimum depth of a binary tree is the shortest path from the root to any leaf node.
By performing a level-order (BFS) traversal, we can return the depth as soon as we hit the first leaf, ensuring it's the minimum.

# Approach
- Use a queue to perform BFS.

- Track the depth of each node in parallel.

- The first time we encounter a leaf node (both left and right are NULL), we return its depth — this is the minimum depth.

# Complexity
- **Time complexity:** `O(n)`
In the worst case (e.g., skewed tree), every node is visited once.

- **Space complexity:** `O(n)`
In the worst case, the queue holds up to n nodes (last level of a complete binary tree).

# Code
```c []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    struct TreeNode* queue[10000];
    int depth[10000];  // To track depth per node
    int front = 0, rear = 0;

    queue[rear] = root;
    depth[rear++] = 1;  // Root is at depth 1

    while (front < rear) {
        struct TreeNode* node = queue[front];
        int d = depth[front];
        front++;

        // If it's a leaf node, return the depth
        if (node->left == NULL && node->right == NULL) {
            return d;
        }

        if (node->left) {
            queue[rear] = node->left;
            depth[rear++] = d + 1;
        }

        if (node->right) {
            queue[rear] = node->right;
            depth[rear++] = d + 1;
        }
    }

    return 0;  // Should never reach here
}

```
