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

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // How many subarrays are possible with sum <= target
        // no. of possible subarrays should be less than equal to m
        auto good = [&](int target) {
            int cnt = 1;
            int sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > target) {
                    return false;
                }
                sum += nums[i];
                if (sum > target) {
                    cnt++;
                    sum = nums[i];
                }
            }
            
            return cnt <= m;
        };
        
        int l = 0;
        int r = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        while (l < r) {
            int mid = (l + r) / 2;
            if (good(mid)) {
                ans = mid;
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};

/*
Time Complexity: O(Sum * Log(Sum))
Space Complexity: O(1)
*/
