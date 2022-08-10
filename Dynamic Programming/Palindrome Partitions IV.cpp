class Solution {
public:
    bool is_palindrome(int i, int j, string &s) {
        while (i <= j) {
            if (s[i] == s[j]) {
                i++, j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    bool helper(int i, int k, string &s, vector<vector<int>> &dp) {
        if (i == s.size()) {
            return k == 0;
        }
        
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        
        if (k == 1) {
            return dp[i][k] = is_palindrome(i, s.size() - 1, s);
        }
        
        if (k == 0) {
            return false;
        }
        
        for (int j = i; j < s.size(); j++) {
            if (is_palindrome(i, j, s)) {
                if (helper(j + 1, k - 1, s, dp)) {
                    return dp[i][k] = true;
                }
            }
        }
        
        return dp[i][k] = false;
    }
    bool checkPartitioning(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int> (4, -1));
        return helper(0, 3, s, dp);
    }
};

/*
Time Complexity: O(N ^ 2)
Space Complexity: O(N) + O(N)
*/
