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
    void inorder(TreeNode *root, vector<int> &path) {
        if (root == NULL) {
            return;
        }
        inorder(root -> left, path);
        path.push_back(root -> val);
        inorder(root -> right, path);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> path1, path2;
        inorder(root1, path1);
        inorder(root2, path2);
        
        vector<int> path;
        int i = 0, j = 0;
        while (i < path1.size() and j < path2.size()) {
            if (path1[i] < path2[j]) {
                path.push_back(path1[i]);
                i++;
            }
            else {
                path.push_back(path2[j]);
                j++;
            }
        }
        
        while (i < path1.size()) {
            path.push_back(path1[i++]);
        }
        
        while (j < path2.size()) {
            path.push_back(path2[j++]);
        }
        
        return path;
    }
};

/*
Time Complexity: O(N + M)
Space Complexity: O(N + M)
*/
