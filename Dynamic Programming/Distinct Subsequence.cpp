class Solution {
public:
    int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (j == 0) return 1;
        if (i == 0) return 0;
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (s[i - 1] == t[j - 1]) {
            return dp[i][j] = helper(i - 1, j - 1, s, t, dp) + helper(i - 1, j, s, t, dp);
        } else {
            return dp[i][j] = helper(i - 1, j, s, t, dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return helper(n, m, s, t, dp);
    }
};

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M) + O(N + M)
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long> (m + 1));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        const int mod = 1e9 + 7;
                
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j] % mod;
                }
            }
        }
        
        return dp[n][m] % mod;        
    }
};

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/
