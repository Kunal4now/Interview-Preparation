// Recursive Traversal
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
    void traversal(TreeNode *root, vector<int> &nodes) {
        if (root == NULL) {
            return;
        }
        traversal(root -> left, nodes);
        nodes.push_back(root -> val);
        traversal(root -> right, nodes);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        }
        vector<int> nodes;
        traversal(root, nodes);
        return nodes;
    }
};

// Iterative Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *node = root;
        vector<int> traversal;
        while (true) {
            if (node != NULL) {
                st.push(node);
                node = node -> left;
            }
            else {
                if (st.empty()) {
                    break;
                }
                node = st.top();
                st.pop();
                traversal.push_back(node -> val);
                node = node -> right;
            }
        }
        return traversal;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
