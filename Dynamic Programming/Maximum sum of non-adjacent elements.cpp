int recurse(int idx, int n, vector<int> &nums, vector<int> &dp) {
	if (idx == 0) {
        return nums[idx];
    }
    if (idx < 0) {
        return 0;
    }
    if (dp[idx] != -1) {
        return dp[idx];
    }
	
    int take = nums[idx] + recurse(idx - 2, n, nums, dp);
    int notTake = recurse(idx - 1, n, nums, dp);
    
    return dp[idx] = max(take, notTake);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return recurse(n - 1, n, nums, dp);
}

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

//Bottom Up
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n + 1, -1);
	
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        int take = nums[i] + (i - 2 >= 0 ? dp[i - 2] : 0);
        int notTake = dp[i - 1];
        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

//Space Optimized
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    int prev = nums[0], prev2 = 0;
	
    for (int i = 1; i < n; i++) {
        int take = nums[i] + (i - 2 >= 0 ? prev2 : 0);
        int notTake = prev;
        int cur = max(take, notTake);
        prev2 = prev, prev = cur;
    }
    return prev;
}

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
