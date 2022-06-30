const int N = 201;
const int mod = 1e9 + 7;
int dp[N][N];

int helper(int n, int m, vector<vector<int>> &a) {
    if (n == 0 and m == 0) {
        return (a[n][m] != -1 ? 1 : 0);
    } 
    if (n < 0 or m < 0) {
        return 0;
    }
    if (dp[n][m] != -1) {
        return dp[n][m];
    }
    if (a[n][m]) {
        return dp[n][m] = 0;
    }
    
    return dp[n][m] = (helper(n - 1, m, a) % mod + helper(n, m - 1, a) % mod) % mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    memset(dp, -1, sizeof(dp));
    return helper(n - 1, m - 1, mat);
}

/*
Time Complexity: O(N * M)
Space Complexity: O(N + M) + O(N * M)
*/

const int mod = 1e9 + 7;
int mazeObstacles(int n, int m, vector< vector< int> > &a) {
    vector<vector<int>> dp(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 and j == 0) {
                dp[i][j] = (a[i][j] != -1 ? 1 : 0);
            } 
            else if (a[i][j] != -1) {
                int up = (i - 1 >= 0 ? dp[i - 1][j] : 0);
                int right = (j - 1 >= 0 ? dp[i][j - 1] : 0);
                dp[i][j] = (up % mod + right % mod) % mod;
            }
        }
    }
    return dp[n - 1][m - 1];
}

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/
