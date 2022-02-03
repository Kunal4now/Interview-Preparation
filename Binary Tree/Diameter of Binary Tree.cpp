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
    int maxDiameter = 0;
    int findHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(findHeight(root -> left), findHeight(root -> right));
    }
    void getMaxDiameter(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        int leftHeight = findHeight(root -> left);
        int rightHeight = findHeight(root -> right);
        
        maxDiameter = max({maxDiameter, leftHeight + rightHeight});
        
        getMaxDiameter(root -> left);
        getMaxDiameter(root -> right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getMaxDiameter(root);
        return maxDiameter;
    }
};
/*
Time Complexity: O(N ^ 2)
Space Complexity: O(N ^ 2)
*/

class Solution {
public:
    int maxDiameter = 0;
    int findHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        int leftHeight = findHeight(root -> left);
        int rightHeight = findHeight(root -> right);
        
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        
        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        findHeight(root);
        return maxDiameter;
    }
};

/*
APPROACH:
=> Whenever we find the height of a binary tree, at the current node we will have the height of its left subtree and height of its right subtree.
=> So we don't need to find height from every node.
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
