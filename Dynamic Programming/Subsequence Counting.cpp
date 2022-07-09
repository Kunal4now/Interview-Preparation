const int N = 1e3 + 10;
const int mod = 1e9 + 7;
int dp[N][N];

int helper(int i, int j, string &t, string &s) {
    if (i == 0 and j == 0) {
        return s[i] == t[j];
    }
    if (i < 0) {
        return 0;
    }
    if (j < 0) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    if (t[i] == s[j]) {
        return dp[i][j] = (helper(i - 1, j - 1, t, s) % mod + helper(i - 1, j, t, s) % mod) % mod;
    } else {
        return dp[i][j] = helper(i - 1, j, t, s) % mod;
    }
} 
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    memset(dp, -1, sizeof(dp));
    return helper(lt - 1, ls - 1, t, s);
} 

/*
APPROACH:
=> Base Case:
      1. When our main string is exhausted and there is still some elements left in other string then we couldn't match fully, so return 0
      2. When our other string is exhausted, that means it completely matched in main string, so return 1
=> We have two possibilites
      1. If both characters match the we can consider that match or not
      2. If they don't match, we don't consider them
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M) + O(N + M)
*/
