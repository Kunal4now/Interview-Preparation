/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode *root, vector<TreeNode*> &arr, int x) {
        if (root == NULL) {
            return false;
        }

        arr.push_back(root);

        if (root -> val == x) {
            return true;
        }

        bool ok = getPath(root -> left, arr, x) or getPath(root -> right, arr, x);

        if (ok) {
            return true;
        }

        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p, path_q;
        getPath(root, path_p, p -> val);
        getPath(root, path_q, q -> val);
        
        int sz = min(path_p.size(), path_q.size());
        TreeNode *lca;
        for (int i = 0; i < sz; i++) {
            if (path_p[i] == path_q[i]) {
                lca = path_p[i];
            }
        }
        return lca;
    }
};

/*
APPROACH:
=> Get the paths of both the nodes from the root node
=> Then just check their ancestors
*/

/*
Time Complexity: O(N)
Space Complexity: O(Path of p + Path of q)
*/

class Solution {
public:
    TreeNode* getLCA(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == NULL || root == p || root == q) {
            return root;
        }
        
        TreeNode *left = getLCA(root -> left, p, q);
        TreeNode *right = getLCA(root -> right, p, q);
        
        if (left == NULL) {
            return right;
        }
        
        if (right == NULL) {
            return left;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = getLCA(root, p, q);
        return res;
    }
};

/*
APPROACH:
https://www.youtube.com/watch?v=_-QHfMDde90&ab_channel=takeUforward
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
