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
    int cnt = 0;
    void dfs(TreeNode *root, int mx) {
        if (root == NULL) {
            return;
        }
        
        if (root -> val >= mx) {
            cnt++;
            mx = root -> val;
        }
        
        dfs(root -> left, mx);
        dfs(root -> right, mx);
    }
    int goodNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        dfs(root, -1e9);
        
        return cnt;
    }
};

/*
Time ComplexityL: O(N)
Space Complexity: O(N)
*/
