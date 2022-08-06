const int N = 1e3 + 10;
long long dp[N];
const long long mod = 1e9 + 7;

int helper(int n) {
    if (n <= 1) {
        return 1;
    }
    
    if (dp[n] != -1) {
        return dp[n];
    }
        
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ((ans % mod) + (helper(i) % mod) * (helper(n - i - 1) % mod) % mod) % mod;
    }
    
    return dp[n] = ans % mod;
}

int Solution::chordCnt(int A) {
    memset(dp, -1, sizeof(dp));
    return helper(A);
}

/*
APPROACH:
=> This is just basically N'th catalan number problem
*/

int Solution::chordCnt(int A) {
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= A; i++) {
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] = ((dp[i] % mod) + (dp[j] % mod) * (dp[i - j - 1] % mod) % mod) % mod;
        }
    }
    return dp[A];
}
