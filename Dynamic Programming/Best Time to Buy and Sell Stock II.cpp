class Solution {
public:
    int helper(int i, bool canBuy, int n, vector<int> &a, vector<vector<int>> &dp) {
        if (i == n) {
            return 0;
        }
        
        if (dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }
        
        if (canBuy) {
            return dp[i][canBuy] = max(-a[i] + helper(i + 1, false, n, a, dp), helper(i + 1, true, n, a, dp));
        } else {
            return dp[i][canBuy] = max(a[i] + helper(i + 1, true, n, a, dp), helper(i + 1, false, n, a, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return helper(0, true, n, prices, dp);
    }
};

/*
APPROACH:
=> We can just try out all possible ways where on a particular day we can sell, buy or hold
*/

/*
Time Complexity: O(N * 2)
Space Complexity: O(N * 2) + O(N)
*/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = max(-a[i] + dp[i + 1][0], dp[i + 1][1]);
            dp[i][0] = max(a[i] + dp[i + 1][1], dp[i + 1][0]);
        }
        
        return dp[0][1];
    }   
};

/*
Time Complexity: O(N * 2)
Space Complexity: O(N * 2)
*/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int> prev(2), cur(2);

        prev[0] = 0, prev[1] = 0;

        for (int i = n - 1; i >= 0; i--) {
        	cur[1] = max(-a[i] + prev[0], prev[1]);
        	cur[0] = max(a[i] + prev[1], prev[0]);
        	prev = cur;
        }

        return cur[1];
    }
};

/*
Time Complexity: O(N * 2)
Space Complexity: O(1)
*/
