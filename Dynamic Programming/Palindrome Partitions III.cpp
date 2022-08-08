class Solution {
public:
    int make_palindrome(int i, int j, string &s) {
        int cnt = 0;
        while (i <= j) {
            cnt += s[i] != s[j];
            i++, j--;
        }
        return cnt;
    }
    
    long long helper(int i, int k, string &s, vector<vector<int>> &dp) {
        if (i == s.size()) {
            return INT_MAX;
        }
        
        if (k == 0) {
            return make_palindrome(i, s.size() - 1, s);
        }
        
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        
        long long ans = INT_MAX;
        for (int j = i; j < s.size(); j++) {
            ans = min({ans, make_palindrome(i, j, s) + helper(j + 1, k - 1, s, dp)});
        }
        
        return dp[i][k] = ans;
    }
    
    int palindromePartition(string s, int k) {
        vector<vector<int>> dp(s.size() + 1, vector<int> (s.size() + 1, - 1));
        return helper(0, k - 1, s, dp);
    }
};

/*
APPROACH:
=> We simply check for every single partition and take the minimum of all the answers that we get
*/

/*
Time Complexity: O(N ^ 2) * K
Space Complexity: O(N * K) + O(N + K)
*/
