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

// DFS Traversal
class Solution {
public:
    void dfs(TreeNode *root, int &ans, int level, int &max_level) {
        if (root == NULL) {
            return;
        }
        if (level > max_level) {
            ans = root -> val;
            max_level = level;
        }
        dfs(root -> left, ans, level + 1, max_level);
        dfs(root -> right, ans, level + 1, max_level);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans, max_level = -1;
        dfs(root, ans, 0, max_level);
        return ans;
    }
};
/*
Time Complexity: O(N)
Spcae Complexity: O(N)
*/
/*
APPROACH:
=> Do a DFS
=> On every level we reach that is greater than previous level, take the value of that node in ans
=> Since it's DFS and we will traverse left first, we will get the leftmost node of every level because
   when we will go to right we would have already traversed to the deepest left nodes and our answer would not change
*/

// BFS Traversal
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int last = root -> val;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto u = q.front();
                q.pop();
                if (i == 0) {
                    last = u -> val;
                }
                if (u -> left) {
                    q.push(u -> left);
                }
                if (u -> right) {
                    q.push(u -> right);
                }
            }
        }
        return last;
    }
};
/*
Time Complexity: O(N)
Spcae Complexity: O(N)
*/
/*
APPROACH:
=> We will traverse the tree level wise
=> For every level just take the first node that you encounter, since it will be the leftmost node in the level
*/
