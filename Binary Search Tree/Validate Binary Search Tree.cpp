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
    bool check(TreeNode *root, long long l, long long r) {
        if (root == NULL) {
            return true;
        }
        if (root -> val >= r or root -> val <= l) {
            return false;
        }
        return check(root -> left, l, root -> val) and check(root -> right, root -> val, r);
    }
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};

/*
APPROACH:
=> We can observe that the nodes in the left side and right side lie in a specific range
=> Nodes in the left side will lie in [some min val, root -> val]
=> Nodes in right side will lie in [root -> val, some max val]
=> Hence we can bound our result and check if the BST satisfy these constraints
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
