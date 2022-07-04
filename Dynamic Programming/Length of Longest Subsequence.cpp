int Solution::longestSubsequenceLength(const vector<int> &a) {
    int n = a.size();
    
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }	

    vector<int> lds(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i] + lds[i] - 1);
    }
    
    return ans;
}

/*
APPROACH:
=> Find the LIS ending at every index (0 to i)
=> Find the LIS from n - 1 to i
=> the ans would be max of sum of both -1 (common element)
*/

/*
Time Complexity: O(N * N)
Space Complexity: O(N)
*/
