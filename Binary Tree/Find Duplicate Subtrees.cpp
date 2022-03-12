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
    string serialize(TreeNode* root, map<string, vector<TreeNode*>> &mp) {
        if (root == NULL) {
            return "";
        }
        string s = "(" + serialize(root -> left, mp) + to_string(root -> val) + serialize(root -> right, mp) + ")";
        mp[s].push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string, vector<TreeNode*>> mp;
        vector<TreeNode*> duplicate;
        serialize(root, mp);
        for (auto &[key, val]: mp) {
            if (val.size() > 1) {
                duplicate.push_back(val[0]);
            }
        }
        return duplicate;
    }
};

/*
Time Complexity: O(N)
*/

/*
APPROACH:
=> Serialize every every subtree and store them in a map
=> If there exists a duplicate serialization in map then push that node in our answer vector
*/
