/*https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=1*/
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

//Iterative Approach
************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
	int ceil = -1;
    while (node != NULL) {
        if (node -> data == x) {
            return x;
        }
        if (node -> data < x) {
            node = node -> right;
        }
        else {
            ceil = node -> data;
            node = node -> left;
        }
    }
    return ceil;
}

/*
Time Complexity: O(Log2N)
Space Complexity: O(1)
*/

//Recursive Approach

void recurse(BinaryTreeNode<int> *node, int x, int &ceil) {
    if (node == NULL) {
        return;
    }
    if (node -> data == x) {
        ceil = x;
        return;
    }
    if (node -> data < x) {
        recurse(node -> right, x, ceil);
    }
    else {
        ceil = node -> data;
        recurse(node -> left, x, ceil);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
	int ceil = -1;
	recurse(node, x, ceil);
    return ceil;
}

/*
Time Complexity: O(Log2N)
Space Complexity: O(Log2N)
*/
