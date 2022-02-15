//https://www.interviewbit.com/problems/path-to-given-node/
bool getPath(TreeNode *root, vector<int> &arr, int x) {
	if (root == NULL) {
		return false;
	}

	arr.push_back(root -> val);

	if (root -> val == x) {
		return true;
	}

	bool ok = getPath(root -> left, arr, x) or getPath(root -> right, arr, x);

	if (ok) {
		return true;
	}

	arr.pop_back();
	return false;
}

vector<int> Solution::solve(TreeNode *A, int B) {
	vector<int> arr;
	if (A == NULL) {
		return arr;
	}

	getPath(A, arr, B);
	return arr;
}

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
