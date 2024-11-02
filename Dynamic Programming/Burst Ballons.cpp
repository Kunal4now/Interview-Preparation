class Solution {
public:
    int dp[301][301];
    int solve(int i, int j, vector<int> &nums) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;
        for (int k = i; k <= j; k++) {
            int left = i >= 1 ? nums[i - 1] : 1;
            int right = j + 1 < nums.size() ? nums[j + 1] : 1;
            int curr = left * nums[k] * right;
            int remaining = solve(i, k - 1, nums) + solve(k + 1, j, nums);
            ans = max(ans, curr + remaining);
        }

        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums.size() - 1, nums);
    }
};

/*
APPROACH:
This is a classic case of Matrix Chain Multiplication or partition DP
1. Just try to partition it at every possible index recursively and compute the desired sum
*/
