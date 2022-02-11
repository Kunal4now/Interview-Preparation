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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            TreeNode *node = get<0>(u);
            int col = get<1>(u), height = get<2>(u);
            mp[col][height].insert(node -> val);
            if (node -> left) {
                q.push({node -> left, col - 1, height + 1});
            }
            if (node -> right) {
                q.push({node -> right, col + 1, height + 1});
            }
        }
        vector<vector<int>> traversal;
        for (auto &col: mp) {
            vector<int> column;
            for (auto &[level, nodes]: col.second) {
                column.insert(column.end(), nodes.begin(), nodes.end());
            }
            traversal.push_back(column);
        }
        return traversal;
    }
}; 

/*
Time Complexity: n * log(height * width)
Space Complexity: O(total nodes + height)
*/
