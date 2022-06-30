int Solution::lis(const vector<int> &a) {
    int n = a.size();
    
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

/*
Time Complexity: O(N * N)
Space Complexity: O(N)
*/
