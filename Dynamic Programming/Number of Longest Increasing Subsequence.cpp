class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        
        int mx = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] and dp[i] < 1 + dp[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    cnt[i] = cnt[j];
                } 
                else if (nums[i] > nums[j] and dp[i] == 1 + dp[j]) {
                    cnt[i] += cnt[j];
                }
            }
            mx = max(mx, dp[i]);
        }
        
        int lcs = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == mx) {
                lcs += cnt[i];
            }
        }
        
        return lcs;
    }
};

/*
Time Complexity: O(N ^ 2)
Space Complexity: O(N)
*/
