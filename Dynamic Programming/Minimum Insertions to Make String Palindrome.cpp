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

int minInsertion(string &str) {
    string s2 = str;
    reverse(s2.begin(), s2.end());
    
    int n = str.size();
    return n - longestCommonSubsequence(str, s2);
}

/*
APPROACH: https://www.youtube.com/watch?v=xPBLEj41rFU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=30&t=231s
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/
