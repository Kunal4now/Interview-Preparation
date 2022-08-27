class Solution {
public:
    int dp[1001][1001];
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
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        memset(dp, -1, sizeof(dp));
        return helper(s.size() - 1, t.size() - 1, s, t);
    }
};

/*
APPROACH:
=> Palindrome is just a string which is same as its reverse
=> We can just find the longest common substring of original strings and its reversed string
*/
