class Solution {
public:
    int pal_dp[1001][1001];
    bool is_palindrome(int i, int j, string &s) {
        if (i == j) return true;
        if (i == j - 1) return s[i] == s[j];
        if (pal_dp[i][j] != -1) return pal_dp[i][j];
        return pal_dp[i][j] = (s[i] == s[j] and is_palindrome(i + 1, j - 1, s));
    }
    int helper(int i, int j, string &s, vector<vector<int>> &dp) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (is_palindrome(i, j, s)) {
            return dp[i][j] = 1 + helper(i + 1, j, s, dp) + helper(i, j - 1, s, dp) - helper(i + 1, j - 1, s, dp);
        } else {
            return dp[i][j] = helper(i + 1, j, s, dp) + helper(i, j - 1, s, dp) - helper(i + 1, j - 1, s, dp);
        }
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        memset(pal_dp, -1, sizeof(pal_dp));
        return helper(0, n - 1, s, dp);
     }
};

/*
APPROACH:
=> We will start from the whole string and if we find that the current substring is palindrome
=> We will recursively search for the substrings with positions i + 1, j and i, j - 1
=> We will have to subtract the palindromes from positions i + 1, j - 1 because they will already be counted in the above cases
*/
