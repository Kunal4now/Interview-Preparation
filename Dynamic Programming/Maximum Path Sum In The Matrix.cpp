const int N = 101;
int dp[N][N];

int helper(int i, int j, vector<vector<int>> &a, int n, int m) {
    if (i == n - 1 and j < m and j >= 0) {
        return a[i][j];
    }
    
    if (i >= n or j >= m or j < 0) {
        return -1e9;
    }
     
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int down = a[i][j] + helper(i + 1, j, a, n, m);
    int downLeft = a[i][j] + helper(i + 1, j - 1, a, n, m);
    int downRight = a[i][j] + helper(i + 1, j + 1, a, n, m);
    
    return dp[i][j] = max({down, downLeft, downRight});
}

int getMaxPathSum(vector<vector<int>> &a) {
    memset(dp, -1, sizeof(dp));
    
    int ans = INT_MIN, n = a.size(), m = a[0].size();
    for (int i = 0; i < m; i++) {
        ans = max(ans, helper(0, i, a, n, m));
    }
    return ans;
}

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M) + (N + M)
*/

int getMaxPathSum(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    
    for (int i = 0; i < m; i++) {
        dp[0][i] = a[0][i];
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = (i - 1 >= 0 ? dp[i - 1][j] : -1e9);
            int upLeft = (i - 1 >= 0 and j + 1 < m ? dp[i - 1][j + 1] : -1e9);
            int upRight = (i - 1 >= 0 and j - 1 >= 0 ? dp[i - 1][j - 1] : -1e9);
            dp[i][j] = a[i][j] + max({up, upLeft, upRight});
        }
    }
    
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/
