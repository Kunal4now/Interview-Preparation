class Solution {
public:
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (j == 0) {
            return i;
        }
        if (i == 0) {
            return j;
        }
        
        if (dp[i - 1][j - 1] != -1) {
            return dp[i - 1][j - 1];
        }
        
        if (s1[i - 1] == s2[j - 1]) {
            return dp[i - 1][j - 1] = helper(i - 1, j - 1, s1, s2, dp); 	
        } else {
            return dp[i - 1][j - 1] = 1 + min({helper(i - 1, j, s1, s2, dp), helper(i, j - 1, s1, s2, dp), helper(i - 1, j - 1, s1, s2, dp)});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        
        return helper(n, m, word1, word2, dp);
    }
};

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M) + O(N + M)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1));
        
        for (int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        
        return dp[n][m];
    }
};

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<int> cur(m + 1, 0), prev(m + 1, 0);
        
        iota(prev.begin(), prev.end(), 0);
        
        for (int i = 1; i <= n; i++) {
            cur[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];
                } else {
                    cur[j] = 1 + min({prev[j], cur[j - 1], prev[j - 1]});
                }
            }
            prev = cur;
        }
        
        return prev[m];
    }
};

/*
Time Complexity: O(N * M)
Space Complexity: O(M)
*/
