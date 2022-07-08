class Solution {
public:
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i < 0 or j < 0) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (s1[i] == s2[j]) {
            return dp[i][j] = max({1 + helper(i - 1, j - 1, s1, s2, dp), helper(i - 1, j, s1, s2, dp), helper(i, j - 1, s1, s2, dp)});
        } 
        else {
            return dp[i][j] = max(helper(i - 1, j, s1, s2, dp), helper(i, j - 1, s1, s2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return helper(n - 1, m - 1, text1, text2, dp);
    }
};

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M) + O(N + M)
*/

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = max({1 + dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/
