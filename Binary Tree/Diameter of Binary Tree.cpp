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
