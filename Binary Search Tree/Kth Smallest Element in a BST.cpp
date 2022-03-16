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
    void dfs(TreeNode *root, vector<int> &nodes) {
        if (root == NULL) {
            return;
        }
        dfs(root -> left, nodes);
        dfs(root -> right, nodes);
        nodes.push_back(root -> val);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        dfs(root, nodes);
        sort(nodes.begin(), nodes.end());
        return nodes[k - 1];
    }
};

/*
Time Complexity: O(NlogN)
Spcae Complexity: O(N)
*/

class Solution {
public:
    void inorder(TreeNode *root, int &cnt, int &ans, int &k) {
        if (root == NULL) {
            return;
        }
        inorder(root -> left, cnt, ans, k);
        if (cnt == k - 1) {
            ans = root -> val;
        }
        cnt++;
        inorder(root -> right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, cnt = 0;
        inorder(root, cnt, ans, k);
        return ans;
    }
};

/*
TIme Complexity: O(N)
Space Complexity: O(N)
*/

/*
IMPORTANT:
=> Inorder traversal of a BST always gives nodes in sorted order
*/
