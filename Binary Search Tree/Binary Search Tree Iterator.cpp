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
void inorder(TreeNode *root, vector<int> &trav) {
    if (root == NULL) {
        return;
    }
    inorder(root -> left, trav);
    trav.push_back(root -> val);
    inorder(root -> right, trav);
}

class BSTIterator {
public:
    vector<int> trav;
    vector<int> :: iterator it;
    BSTIterator(TreeNode* root) {
        inorder(root, trav);
        it = trav.begin();
        --it;
    }
    
    int next() {
        it++;
        return *it;
    }
    
    bool hasNext() {
        auto it2 = it;
        ++it2;
        if (it2 == trav.end()) {
            return false;
        }
        return true;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


class BSTIterator {
    stack<TreeNode*> nodes;
    void pushAll(TreeNode *cur) {
        while (cur != NULL) {
            nodes.push(cur);
            cur = cur -> left;
        }
        return;
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto cur = nodes.top(); nodes.pop();
        pushAll(cur -> right);
        return cur -> val;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
};

/*
APPROACH:
=> Just do an iterative inorder traversal till you get the next node
=> So in this case we will have at max H nodes in our stack
=> And since there are about N calls the time complexity would come out to be O(1)
*/

/*
Time Complexity: O(1)
Space Complexity: O(H)
*/
