class Solution {
public:
    int dp[10007];
    int helper(int idx, vector<int> &a) {
        if (idx >= a.size()) {
            return 1e6;
        }
        
        if (idx == a.size() - 1) {
            return 0;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int mn = 1e6;
        for (int i = 1; i <= a[idx]; i++) {
            if (i + idx < a.size()) {
                mn = min(mn, 1 + helper(idx + i, a));
            }
        }
        
        return dp[idx] = mn;
    }
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return helper(0, nums);
    }
};

/*
APPROACH:
=> Since every index tells us how far we can jump
=> we can try out all possible lenghts of our jumps
*/

/*
Time Complexity: O(N * N)
Space Complexity: O(N)
*/
