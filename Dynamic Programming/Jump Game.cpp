class Solution {
public:
    int helper(int i, vector<int> &nums, int n, vector<int> &dp) {
        if (i >= n) {
            return false;
        }
        
        if (i == n - 1) {
            return true;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
            
        bool ok = false;
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < n) {
                ok |= helper(i + j, nums, n, dp);
                if (ok) {
                    return dp[i] = true;
                } 
            }
        }
        
        return dp[i] = ok;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, n, dp);
    }
};

/*
Time Complexity: O(N ^ 2)
Space Complexity: O(N) + O(N)
*/
