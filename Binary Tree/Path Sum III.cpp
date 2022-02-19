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
    int pathSum(TreeNode* root, int targetSum) {
        if (root != NULL) {
            dfs(root, targetSum);
            pathSum(root -> left, targetSum);
            pathSum(root -> right, targetSum);
        }
        return cnt;
    }
    void dfs(TreeNode *root, int sum) {
        if (root == NULL) {
            return;
        }
        if (root -> val == sum) {
            cnt++;
        }
        dfs(root -> left, sum - root -> val);
        dfs(root -> right, sum - root -> val);
    }
};

/*
APPROACH:
=> Do a DFS on every node and count all the paths that have sum == targetSum
*/

/*
Time Complexity: O(N ^ 2) 
Space Complexity: O(N)
*/
