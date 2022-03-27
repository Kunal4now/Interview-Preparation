/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    bool validate(Node *root, int l, int r) {
        if (root == NULL) {
            return true;
        }
        if (root -> data <= l or root -> data >= r) {
            return false;
        }
        return validate(root -> left, l, root -> data) and validate(root -> right, root -> data, r);
    }
    int count(Node *root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + count(root -> left) + count(root -> right);
    }
    int largestBst(Node *root) {
        if (root == NULL) {
            return 0;
        }
        if (validate(root, INT_MIN, INT_MAX)) {
            return count(root);
        }
        return max(largestBst(root ->left), largestBst(root -> right));
    }
};

/*
APPROACH:
=> For every node, check if its subtree is a BST:
      if its a BST then count the no. of nodes in it and take max
*/

/*
Time Complexity: O(N^2)
*/
