long long add(long long x, long long y, long long mod) {
    return (x + y) % mod;
}
long long sub(long long x, long long y, long long mod) {
    return (x - y) + (x >= y ? 0: mod);
}
long long helper(int i, int j, string &s, vector<vector<long long>> &dp) {
    const long long mod = 1e9 + 7;
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j] % mod;
    }
    long long ans = sub(add(helper(i + 1, j, s, dp), helper(i, j - 1, s, dp), mod), helper(i + 1, j - 1, s, dp), mod);
    if (s[i] == s[j]) {
        ans = add(add(ans, 1, mod), helper(i + 1, j - 1, s, dp), mod);
    }
    return dp[i][j] = ans % mod;
}
long long  countPS(string s) {
    int n = s.size();
    vector<vector<long long>> dp(n, vector<long long> (n, -1));
    return helper(0, n - 1, s, dp);
}
