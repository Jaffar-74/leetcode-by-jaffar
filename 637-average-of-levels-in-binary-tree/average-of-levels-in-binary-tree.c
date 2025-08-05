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