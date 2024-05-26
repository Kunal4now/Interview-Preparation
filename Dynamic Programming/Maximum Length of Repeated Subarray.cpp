class Solution {
public:
    int findLength(vector<int>& text1, vector<int>& text2) {
                int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

/*
APPROACH: This is just LCS but with consecutive elements
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/
