const int N = 110;
const int K = 1e3 + 10;

int dp[N][K];

int helper(int idx, int tar, vector<int> &a) {
    if (tar == 0) {
        return 1;
    }
   
    if (idx == 0) {
        return a[idx] == tar;
    }
    
    if (dp[idx][tar] != -1) {
        return dp[idx][tar];
    }
    
    int take = 0;
    if (a[idx] <= tar) {
        take = helper(idx - 1, tar - a[idx], a);
    }
    int notTake = helper(idx - 1, tar, a);
    
    return dp[idx][tar] = take + notTake;
}

int findWays(vector<int> &num, int tar) {
    memset(dp, -1, sizeof(dp));
    int n = num.size();
    return helper(n - 1, tar, num);
}

/*
Time Complexity: O(N * tar)
Space Complexity: O(N * tar) + O(N)
*/

int findWays(vector<int> &a, int tar) {
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int> (tar + 1));
    
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }
    
    if (a[0] <= tar) {
        dp[0][a[0]] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= tar; j++) {
            int take = 0;
            if (a[i] <= j) {
                take = dp[i - 1][j - a[i]];
            }
            int notTake = dp[i - 1][j];
            dp[i][j] = take + notTake;
        }
    }
    
    return dp[n - 1][tar];
}

/*
Time Complexity: O(N * tar)
Space Complexity: O(N * tar)
*/
