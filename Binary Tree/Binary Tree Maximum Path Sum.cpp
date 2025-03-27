/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMaxPath(TreeNode* root, int &maxSum) {
        if (root == NULL) {
            return 0;
        }
        
        int leftSum = getMaxPath(root -> left, maxSum);
        int rightSum = getMaxPath(root -> right, maxSum);
        
        leftSum = max(leftSum, 0);
        rightSum = max(rightSum, 0);
            
        maxSum = max(maxSum, root -> val + leftSum + rightSum);
        
        return root -> val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = -1e9;
        getMaxPath(root, maxSum);
        return maxSum;
    }
};

/*
APPROACH:
This is just the extension of the problem max path of a binary tree
1. We try to calculate the max path of a binary tree
2. We get letPath and rightpath in the process
3. Our answer is the node + leftSum + rightSum
4. Because we need to check sum from every node
*/

/*
Reference: https://www.youtube.com/watch?v=WszrfSwMz58&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=18&t=928s&ab_channel=takeUforward
*/
