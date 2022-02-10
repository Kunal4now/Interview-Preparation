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

/*
General Thoughts:
=> We just need to compare two nodes which lie opposite to each other in a mirror
=> Just simulate the process and you would get the answer
=> Can be achieved by a simple BFS or by recursion
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        } 
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root -> left, root -> right});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (!p.first && !p.second) {
                continue;
            }
            if (!p.first || !p.second) {
                return false;
            }
            if (p.first -> val != p.second -> val) {
                return false;
            }
            q.push({p.first -> left, p.second -> right});
            q.push({p.first -> right, p.second -> left});
        }
        return true;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        } 
        return checkSymmetric(root -> left, root -> right);
    }
    bool checkSymmetric(TreeNode *leftNode, TreeNode *rightNode) {
        if (!leftNode && !rightNode) {
            return true;
        }
        if (!leftNode || !rightNode) {
            return false;
        }
        return (leftNode -> val == rightNode -> val) && checkSymmetric(leftNode -> left, rightNode -> right) && checkSymmetric(leftNode -> right, rightNode -> left);
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
