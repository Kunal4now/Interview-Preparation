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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        }
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        map<int, int> mp;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            mp[u.second] = u.first -> val;
            if (u.first -> left) {
                q.push({u.first -> left, u.second + 1});
            }
            if (u.first -> right) {
                q.push({u.first -> right, u.second + 1});
            }
        }
        vector<int> traversal;
        for (auto x: mp) {
            traversal.push_back(x.second);
        }
        return traversal;
    }
};
