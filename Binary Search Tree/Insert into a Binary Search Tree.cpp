//Iterative Approach

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode *new_node = new TreeNode(val);
            return new_node;
        }
        TreeNode *root_new = root;
        while (root != NULL) {
            if (root -> val > val) {
                if (root -> left == NULL) {
                    TreeNode *new_node = new TreeNode(val);
                    root -> left = new_node;
                    break;
                }
                root = root -> left;
            }
            else {
                if (root -> right == NULL) {
                    TreeNode *new_node = new TreeNode(val);
                    root -> right = new_node;
                    break;
                }
                root = root -> right;
            }
        }
        return root_new;
    }
};

/*
Time Compleixty: O(Log2N)
Space Complexity: O(1)
*/

//Recursive Approach

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
    void recurse(TreeNode *root, int val) {
        if (root == NULL) {
            return;
        }
        TreeNode *new_node = new TreeNode(val);
        if (root -> val > val) {
            if (root -> left == NULL) {
                root -> left = new_node;
                return;
            }
            recurse(root -> left, val);
        }
        else {
            if (root -> right == NULL) {
                root -> right = new_node;
                return;
            }
            recurse(root -> right, val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode *new_node = new TreeNode(val);
            return new_node;
        }
        TreeNode *root_new = root;
        recurse(root, val);
        return root_new;
    }
};

/*
Time Compleixty: O(Log2N)
Space Complexity: O(Log2N)
*/
