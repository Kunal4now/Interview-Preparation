int helper(int i, int j, vector<int> &a, vector<vector<int>> &dp) {
    if (i == j) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int mn = 1e9;
    for (int k = i; k < j; k++) {
        mn = min(mn, a[i - 1] * a[j] * a[k] + helper(i, k, a, dp) + helper(k + 1, j, a, dp));
    }
    return dp[i][j] = mn;
}
int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int> (N, -1));
    return helper(1, N - 1, arr, dp);
}
