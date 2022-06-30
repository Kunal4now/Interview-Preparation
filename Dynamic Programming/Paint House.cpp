int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    
    vector<array<int, 3>> dp(n);
    dp[0][0] = a[0][0], dp[0][1] = a[0][1], dp[0][2] = a[0][2];
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = a[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = a[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }
    
    return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

/*
Time Complexity: O(N)
Space Complexity: O(N * 3)
*/

int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    
    array<int, 3> dp;
    dp[0] = a[0][0], dp[1] = a[0][1], dp[2] = a[0][2];
    
    array<int, 3> temp_dp = dp;
    for (int i = 1; i < n; i++) {
        dp[0] = a[i][0] + min(temp_dp[1], temp_dp[2]);
        dp[1] = a[i][1] + min(temp_dp[0], temp_dp[2]);
        dp[2] = a[i][2] + min(temp_dp[0], temp_dp[1]);
        temp_dp = dp;
    }
    
    return min({dp[0], dp[1], dp[2]});
}

/*
APPROACH:
=> Since current state only depends upon previous state
=> We can only store the previous state and note care about other
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
