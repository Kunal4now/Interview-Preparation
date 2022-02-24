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
    int findRightHeight(TreeNode *node) {
        int height = 0;
        while (node) {
            height++;
            node = node -> right;
        }
        return height;
    }
    int findLeftHeight(TreeNode *node) {
        int height = 0;
        while (node) {
            height++;
            node = node -> left;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);
        
        if (rightHeight == leftHeight) {
            return (1 << rightHeight) - 1;
        }
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

/*
Time Complexity: O(log(N) * log(N))
Space Complexity: O(log(N))
*/
