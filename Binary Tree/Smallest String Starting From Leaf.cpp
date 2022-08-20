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
    string ans = "";
    void dfs(TreeNode *root, string s) {
        if (root == NULL) {
            return;
        }
        
        if (!root -> left and !root -> right) {
            s += char(root -> val + 97);
            string tmp = s;
            reverse(tmp.begin(), tmp.end());
            ans = min(ans, tmp);
            return;
        }
        
        s += char(root -> val + 97);
        dfs(root -> left, s);
        dfs(root -> right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
        for (int i = 0; i < 8600; i++) {
            ans += 'z';
        }
        
        string s = "";
        dfs(root, s);
        
        return ans;
    }
};
