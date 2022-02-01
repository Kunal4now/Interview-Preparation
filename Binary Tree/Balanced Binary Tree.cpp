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
    int checkBalanced(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = checkBalanced(node -> left);
        if (leftHeight == - 1) {
            return -1;
        }
        int rightHeight = checkBalanced(node -> right);
        if (rightHeight == - 1) {
            return -1;
        }
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        return (checkBalanced(root) == -1 ? false : true);
    }
};

/*
Balanced Binary Tree:
=> The absolute difference between height of left subtree and right subtree should be less than equal to one
=> abs(height(left) - height(right)) <= 1
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
