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
    
    int helper(int i, string &s, vector<int> &dp) {
        if (i == s.size()) {
            return 0;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
        
        int ans = INT_MAX;
        for (int j = i; j < s.size(); j++) {
            if (is_palindrome(i, j, s)) {
                ans = min(ans, helper(j + 1, s, dp));
            }
        }
        
        ans += 1;
        return dp[i] = ans;
    }

    int minCut(string s) {
        vector<int> dp(s.size() + 1, -1);
        return helper(0, s, dp) - 1;
    }
};

/*
APPROACH:
=> We can try out all valid partitions and take the one which have minimum cuts
=> In answer, we will get total partitions, but we need cuts so we have to decrement the answer by 1
*/

/*
Time Complexity: O(N ^ 2) + O(N ^ 2)
Space Complexity: O(N)
*/
