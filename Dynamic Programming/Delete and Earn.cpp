class Solution {
public:
    int recurse(int idx, vector<int> &nums, vector<int> &dp) {
        if (idx >= nums.size()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int profit = nums[idx];
        int skip = idx + 1;
        while (skip < nums.size() && nums[idx] == nums[skip]) {
            profit += nums[idx];
            skip++;
        }
        while (skip < nums.size() && nums[skip] == nums[idx] + 1) {
            skip++;
        }
        profit += recurse(skip, nums, dp);
        int skipped = recurse(idx + 1, nums, dp);
        return dp[idx] = max(profit, skipped);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(int(nums.size()), -1);
        return recurse(0, nums, dp);
    }
};

/*
APPROACH:
=> Here dp[idx] = maximum profit we can get if we take the idx'th element or skip it
*/
