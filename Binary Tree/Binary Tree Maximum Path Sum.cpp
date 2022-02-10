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
Reference: https://www.youtube.com/watch?v=WszrfSwMz58&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=18&t=928s&ab_channel=takeUforward
*/
