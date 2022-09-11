class Solution {
public:
    int helper(int idx, int m, vector<int> &a, vector<vector<int>> &dp) {
        if (m == 0) {
            return accumulate(a.begin() + idx, a.end(), 0);
        }
        
        if (dp[idx][m] != -1) {
            return dp[idx][m];
        }
        
        int minSum = INT_MAX, sum = 0;
        for (int i = idx; i < a.size(); i++) {
            sum += a[i];
            minSum = min(minSum, max(sum, helper(i + 1, m - 1, a, dp)));
        }
        
        return dp[idx][m] = minSum;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size(); 
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));        
        
        return helper(0, m - 1, nums, dp);
    }
};

/*
APPROACH:
=> We will try out all partitions and get the one with min ans
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M) + O(N + M)
*/
