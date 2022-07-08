int lcs(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
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

int canYouMake(string &str, string &ptr) {
    int n = str.size(), m = ptr.size();
    
    int len = lcs(str, ptr);
    
    int needToAdd = m - len; // length of the part that does not exist in str
    
    int uncommon = n - len; // length of the part which exists in str but is absent in ptr
    
    return uncommon + needToAdd;
}

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M);
*/
