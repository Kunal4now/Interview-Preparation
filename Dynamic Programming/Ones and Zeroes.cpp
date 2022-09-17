class Solution {
public:
    int dp[601][101][101];
    int helper(int idx, int m, int n, vector<int> &one, vector<int> &zero) {
        if (idx >= one.size()) {
            return 0;
        }
        
        if (dp[idx][m][n] != -1) {
            return dp[idx][m][n];
        }
            
        int ans = 0;
        if (m - zero[idx] >= 0 and n - one[idx] >= 0) {
            ans = 1 + helper(idx + 1, m - zero[idx], n - one[idx], one, zero);
        }
        ans = max(ans, helper(idx + 1, m, n, one, zero));
        
        return dp[idx][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz = strs.size();
        vector<int> one(sz, 0), zero(sz, 0);
        
        for (int i = 0; i < strs.size(); i++) {
            int o = 0, z = 0;
            for (auto &x: strs[i]) {
                o += x == '1';
                z += x == '0'; 
            }
            one[i] = o, zero[i] = z;
        }
        
        memset(dp, -1, sizeof(dp));
        
        return helper(0, m, n, one, zero);
    }
};

/*
APPROACH:
=> Normal knapsack approach
*/
