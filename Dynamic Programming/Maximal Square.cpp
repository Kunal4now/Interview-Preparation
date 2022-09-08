class Solution {
public:
    int dp[301][301];
    int helper(int i, int j, vector<vector<char>> &matrix, int &mx) {
        if (i >= matrix.size() or j >= matrix[0].size()) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int diagonal = helper(i + 1, j + 1, matrix, mx);
        int right = helper(i, j + 1, matrix, mx);
        int bottom = helper(i + 1, j, matrix, mx);
        
        if (matrix[i][j] == '1') {
            int ans = 1 + min({diagonal, right, bottom});
            mx = max(mx, ans);
            return dp[i][j] = ans;
        } else {
            return dp[i][j] = 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int mx = 0;
        memset(dp, -1, sizeof(dp));
        helper(0, 0, matrix, mx);
        return mx * mx;
    }
};

/*
APPROACH:
=> Try to extend square
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M) + O(N + M)
*/
