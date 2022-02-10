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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>> ();
        }
        
        vector<vector<int>> traversal;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int flip = 1;
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> level_nodes(n);
            for (int i = 0; i < n; i++) {
                TreeNode *p = q.front();
                q.pop();
                if (flip) {
                    level_nodes[i] = p -> val; 
                } else {
                    level_nodes[n - i - 1] = p -> val;
                }
                if (p -> left) {
                    q.push(p -> left);
                }
                if (p -> right) {
                    q.push(p -> right);
                }
            }
            traversal.push_back(level_nodes);
            flip = 1 - flip;
        }
        return traversal;
    }
};

/*
APPROACH:
=> Do a simple BFS and store the nodes of a level in a alternate fashion
=> like when flip is 1: store normally
=> when flip is 0: store in reverse
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
