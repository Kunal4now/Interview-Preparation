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
    int idx = 0;
    TreeNode* builder(int left, int right, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp) {
        if (left > right) {
            return NULL;
        }

        int cur = preorder[idx++];
        TreeNode *newNode = new TreeNode(cur);

        if (left == right) {
            return newNode;
        }

        int inorderIdx = mp[cur];

        newNode -> left = builder(left, inorderIdx - 1, preorder, inorder, mp);
        newNode -> right = builder(inorderIdx + 1, right, preorder, inorder, mp);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return builder(0, preorder.size() - 1, preorder, inorder, mp);
    }
};

/*
APPROACH:
preorder = [3,9,20,15,7]
inorder =  [9,3,15,20,7]

Key observations:
1. the first node in the pre order traversal is root node

Key points:

First element of preorder is always the root
Use inorder to determine left and right subtree sizes
Recursively build left and right subtrees by adjusting index ranges


The 3 in preorder is root and 3 in inorder array will tell that all the elements in left to 3 in inorder will lie in left subtree and left to 3 would lie in right 
subtree
*/
