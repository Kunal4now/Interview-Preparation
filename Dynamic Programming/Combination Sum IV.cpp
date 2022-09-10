class Solution {
public:
    int helper(int idx, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if (idx >= nums.size() or target <= 0) {
            return target == 0;
        }
        
        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }
        
        int take = helper(0, target - nums[idx], nums, dp);
        int notTake = helper(idx + 1, target, nums, dp);
        
        return dp[idx][target] = take + notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (target + 1, -1));
        return helper(0, target, nums, dp);
    }
};
