class Solution {
public:
    bool helper(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<int>> &dp) {
        if (i < 0 and j < 0 and k < 0) {
            return true;
        }
        if (i >= 0 and j >= 0 and dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (i >= 0 and j >= 0 and s1[i] == s3[k] and s2[j] == s3[k]) {
            return dp[i][j] = helper(i - 1, j, k - 1, s1, s2, s3, dp) or helper(i, j - 1, k - 1, s1, s2, s3, dp);
        } else if (i >= 0 and s1[i] == s3[k]) {
            return helper(i - 1, j, k - 1, s1, s2, s3, dp);
        } else if (j >= 0 and s2[j] == s3[k]) {
            return helper(i, j - 1, k - 1, s1, s2, s3, dp);
        } else {
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), i = s3.size();
        
        if (n + m != i) {
            return false;
        }
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return helper(n - 1, m - 1, i - 1, s1, s2, s3, dp);
    }
};
