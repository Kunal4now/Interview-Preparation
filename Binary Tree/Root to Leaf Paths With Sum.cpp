/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void getPath(TreeNode *root, int cur, int sum, vector<int> &path, vector<vector<int>> &paths) {
    if (root == NULL) {
        return;
    }

    cur += root -> val;
    path.push_back(root -> val);
    if (!root -> left and !root -> right) {
        if (cur == sum) {
            paths.push_back(path);
        }
    }

    getPath(root -> left, cur, sum, path, paths);
    getPath(root -> right, cur, sum, path, paths);
    path.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<int> path;
    vector<vector<int>> paths;
    getPath(A, 0, B, path, paths);
    return paths;
}

// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/
