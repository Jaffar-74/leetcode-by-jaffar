# Intuition
The problem requires computing the average value of nodes at each level of a binary tree. A level-order traversal (BFS) naturally allows us to visit nodes level-by-level. By summing the node values at each level and dividing by the number of nodes at that level, we can compute the average for each level efficiently.

# Approach
**1.** **Use a queue for BFS traversal:** Start with the root node and perform a level-order traversal.<br>
**2.** **Track nodes at each level:** For every iteration of the outer loop, process all nodes at the current level.<br>
**3.** **Compute the average:**- Sum all node values at the current level. Divide the sum by the number of nodes at that level to get the average. <br>
**4.** **Store the result** in an output array and return it at the end.

# Complexity
- **Time complexity:** Each node in the tree is visited exactly once. N is the number of nodes in the binary tree.

- **Space complexity:** Where `W` is the maximum number of nodes at any level (the width of the tree). The queue may hold up to W nodes at once during traversal. Additionally, space is used for the result array (`O(H)` where H is height of the tree, since we store one average per level).

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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
 
if (!root){
    *returnSize = 0;
    return NULL;
}

//queue for level order traversal
struct TreeNode* queue[10000];
int front = 0, rear = 0;
//result array to store averages
double *result = malloc(sizeof(double)*1000);
int resultindex = 0;

queue[rear++] = root;

while(front<rear){
    int level_size = rear-front;
    double level_sum = 0;

    for(int i = 0; i<level_size; i++){
        struct TreeNode* node = queue[front++];
        level_sum += node->val;

        if(node->left){
            queue[rear++] = node->left;
        }
        if(node->right){
            queue[rear++] = node->right;
        }
    }
    result[resultindex++] = level_sum/level_size;
}

*returnSize = resultindex;
return result;

}   

```
