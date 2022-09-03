/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int rangeSum(TreeNode<int> *root, int low, int high) {
    if (root == NULL) {
        return 0;
    }
    
    int sum = 0;
    if (root -> data >= low and root -> data <= high) {
        sum += root -> data;
    }
    
    int leftSum = rangeSum(root -> left, low, high);
    int rightSum = rangeSum(root -> right, low, high);
    return leftSum + rightSum + sum;
}

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
