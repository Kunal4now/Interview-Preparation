/*class BinaryTreeNode {
public :
    T data;
    BinaryTreeNode < T > *left;
    BinaryTreeNode < T > *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};*/

// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos&leftPanelTab=0

void changeTree(BinaryTreeNode<int> *root) {
	if (root == NULL) {
		return;
	}

	int left = 0, right = 0;
	if (root -> left) left = root -> left -> data;
	if (root -> right) right = root -> right -> data;

	if (left + right >= root -> data) {
		root -> data = left + right;
	} 
	else {
		if (root -> left) {
			root -> left -> data = root -> data;
		}
		if (root -> right) {
			root -> right -> data = root -> data;
		}
	}

	changeTree(root -> left);
	changeTree(root -> right);

	int tot = 0;
	if (root -> left) tot += root -> left -> data;
	if (root -> right) tot += root -> right -> data;
	if (root -> left or root -> right) root -> data = tot;
}

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

/*
THOUGHTS:
=> Since the problem doesnt want us to minimize the number of increments, we can take this to our advantage
=> 1. On the current node first we will check whether the sum of both the child nodes is greater than than parent
=>    (a) If the sum of both childs is greater, we will just assign the sum of childrens to the parent as the new value
      (b) If the sum if less, then assign the value of partent to both the childrens
=> 2. While returning we will check if any of the left or right child exists then we will assign their sum to the parent
*/
