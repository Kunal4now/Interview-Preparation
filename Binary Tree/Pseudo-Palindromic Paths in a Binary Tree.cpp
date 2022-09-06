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
    vector<vector<int>> paths;
    int cnt = 0;
    void findPath(TreeNode *root, vector<int> &mp) {
        if (root == NULL) {
            return;
        }
        
        mp[root -> val]++;
        
        if (!root -> left and !root -> right) {
            int even = 0, odd = 0;
            for (int i = 1; i <= 9; i++) {
                even += mp[i] % 2 == 0; 
                odd += mp[i] % 2 != 0;
            }
            if (odd <= 1) {
                cnt++;
            }
        }
        
        findPath(root -> left, mp);
        findPath(root -> right, mp);
        
        mp[root -> val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> mp(10, 0);
        findPath(root, mp);
        
        return cnt;
    }
};

/*
APPROACH:
=> Just store the frequency of every element in path
=> Check whether all elements have even frequency or only 1 element have odd frequency
=> store the count by checking above condition
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
