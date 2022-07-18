/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *LCA(TreeNode<int> *root, int p, int q) {
    if (root == NULL) {
        return NULL;
    }
    if (root -> val == p or root -> val == q) {
        return root;
    }
    
    TreeNode<int> *l = LCA(root -> left, p, q);
    TreeNode<int> *r = LCA(root -> right, p, q);
    
    if (l == NULL) {
        return r;
    }
    if (r == NULL) {
        return l;
    }
    
    return root;
}

int pathLength(TreeNode<int> *root, int x, int len) {
    if (root == NULL) {
        return -1;
    }
    
    if (root -> val == x) {
        return len;
    }
    
    int left = pathLength(root -> left, x, len + 1);
    if (left == -1) {
        return pathLength(root -> right, x, len + 1);
    }
    
    return left;
}

int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2) {
    TreeNode<int> *lca = LCA(root, node1, node2);
    int x = pathLength(lca, node1, 0);
    int y = pathLength(lca, node2, 0);
    
    if (x == -1 or y == -1) {
        return -1;
    }
    return x + y;
}
