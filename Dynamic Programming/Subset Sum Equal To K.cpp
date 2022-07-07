const int N = 1e3 + 10;
int dp[N][N];

bool helper(int idx, int n, int k, vector<int> &a) {
    if (k == 0) {
        return true;
    }
    
    if (idx == 0) {
        return k == a[idx];
    }
    
    if (dp[idx][k] != -1) {
        return dp[idx][k];
    } 
    
    bool take = false;
    if (a[idx] <= k) {
        take = helper(idx - 1, n, k - a[idx], a);
    }
    bool notTake = helper(idx - 1, n, k, a);
    
    return dp[idx][k] = (take or notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    memset(dp, -1, sizeof(dp));
    return helper(n - 1, n, k, arr);
}

/*
Time Complexity: O(N * K)
Space complexity: O(N * K) + O(N)
*/

bool subsetSumToK(int n, int k, vector<int> &a) {
    bool dp[n + 1][k + 1];
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    
    for (int i = 1; i <= k; i++) {
        dp[0][i] = a[0] == i; 
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool take = false;
            if (j >= a[i]) {
                take = dp[i - 1][j - a[i]];
            }
            bool notTake = dp[i - 1][j];
            dp[i][j] = take or notTake;
        }
    }
    
    return dp[n - 1][k];
}

/*
Time Complexity: O(N * K)
Space complexity: O(N * K)
*/

bool subsetSumToK(int n, int k, vector<int> &a) {
    vector<bool> cur(k + 1, false), prev(k + 1, false);
    
    prev[0] = cur[0] = true;
    prev[a[0]] = true; 
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool take = false;
            if (j >= a[i]) {
                take = prev[j - a[i]];
            }
            bool notTake = prev[j];
            cur[j] = take or notTake;
        }
        prev = cur;
    }
    
    return cur[k];
}

/*
Time Complexity: O(N * K)
Space complexity: O(K)
*/
