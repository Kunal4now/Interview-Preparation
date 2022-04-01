class Solution {
public:
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> tmp1(nums.begin() + 1, nums.end());
        vector<int> tmp2(nums.begin(), nums.end() - 1);
        return max(maximumNonAdjacentSum(tmp1), maximumNonAdjacentSum(tmp2));
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N + N)
*/

class Solution {
public:
    int sum(vector<int> &nums, int l, int r){
        int n = nums.size();
        int prev = 0, prev2 = 0;

        for (int i = l; i <= r; i++) {
            int take = nums[i] + prev2;
            int notTake = prev;
            int cur = max(take, notTake);
            prev2 = prev, prev = cur;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(sum(nums, 0, n - 2), sum(nums, 1, n - 1));
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> dp(2, vector<int> (n));
        for (int i = 0; i < n - 1; i++) {
            dp[0][i] = max(nums[i] + (i - 2 >= 0 ? dp[0][i - 2] : 0), (i - 1 >= 0 ? dp[0][i - 1] : 0));
            dp[1][i + 1] = max(nums[i + 1] + (i - 1 >= 0 ? dp[1][i - 1] : 0), dp[1][i]);
        }
        return max(dp[0][n - 2], dp[1][n - 1]);
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
