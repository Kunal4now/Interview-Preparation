// Iterative Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        }
        stack<TreeNode*> st;
        st.push(root);
        vector<int> traversal;
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            traversal.push_back(cur -> val);
            if (cur -> right) {
                st.push(cur -> right);
            }
            if (cur -> left) {
                st.push(cur -> left);
            }
        }
        return traversal;
    }
};

//Recursive Traverasal
class Solution {
public:
    void traversal(TreeNode *root, vector<int> &nodes) {
        if (root == NULL) {
            return;
        }
        nodes.push_back(root -> val);
        traversal(root -> left, nodes);
        traversal(root -> right, nodes);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return vector<int>();
        }
        vector<int> nodes;
        traversal(root, nodes);
        return nodes;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
