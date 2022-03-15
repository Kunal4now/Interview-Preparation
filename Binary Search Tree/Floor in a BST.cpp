//https://www.codingninjas.com/codestudio/problems/-floor-in--bst_920457?leftPanelTab=1

/*Iterative Approach*/

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
int floorInBST(TreeNode<int> * root, int X) {
	int floor = 0;
    while (root != NULL) {
		if (root -> val == X) {
            return X;
        }
        if (root -> val > X) {
            root = root -> left;
        }
        else {
            floor = root -> val;
            root = root -> right;
        }
    }
    return floor;
}

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

/*Recursive Approach*/

void recurse(TreeNode<int> *root, int X, int &floor) {
    if (root == NULL) {
        return;
    }
    if (root -> val > X) {
        recurse(root -> left, X, floor);
    }
    else {
        floor = root -> val;
        recurse(root -> right, X, floor);
    }
}
int floorInBST(TreeNode<int> * root, int X) {
	int floor = 0;
    recurse(root, X, floor);
    return floor;
}

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
