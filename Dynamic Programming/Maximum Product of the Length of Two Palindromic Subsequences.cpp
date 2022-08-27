class Solution {
public:
    int dp[13][13];
    int helper(int i, int j, string &s, string &t) {
        if (i < 0 or j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == t[j]) {
            return dp[i][j] = 1 + helper(i - 1, j - 1, s, t);
        }
        else {
            return dp[i][j] = max(helper(i - 1, j, s, t), helper(i, j - 1, s, t));
        }
    }
    int maxProduct(string s) {
        int n = s.size();
        int ans = 0;
        
        for (int bit = 0; bit < (1 << n); bit++) {
            string first = "", second = "";
            for (int i = 0; i < n; i++) {
                if (bit & (1 << i)) {
                    first += s[i];
                } else {
                    second += s[i];
                }
            }
            string revFirst = first, revSecond = second;
            
            reverse(revFirst.begin(), revFirst.end());
            reverse(revSecond.begin(), revSecond.end());
            
            memset(dp, -1, sizeof(dp));
            int fir = helper(first.size() - 1, revFirst.size() - 1, first, revFirst);
            memset(dp, -1, sizeof(dp));
            int sec = helper(second.size() - 1, revSecond.size() - 1, second, revSecond);
            
            ans = max(ans, fir * sec);
        }
        return ans;
    }
};

/*
APPROACH:
=> We can use bitmasks for this problem
=> A particular mask will give us two different subsets, the one whose bits are on and the one whose bits are off
=> Then we can simply apply the LCS on both of the strings and find the max ans
*/
