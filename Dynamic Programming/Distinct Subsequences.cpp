class Solution {
public:
    int findDistinct(int sIdx, int tIdx, string &s, string &t, vector<vector<int>> &dp) {
        if (tIdx >= t.size()) {
            return 1;
        }
        if (sIdx >= s.size()) {
            return 0;
        }

        if (dp[sIdx][tIdx] != -1) {
            return dp[sIdx][tIdx];
        }

        int match = 0, notMatch = 0;
        if (s[sIdx] == t[tIdx]) {
            match = findDistinct(sIdx + 1, tIdx + 1, s, t, dp) + findDistinct(sIdx + 1, tIdx, s, t, dp);
        } else {
            notMatch = findDistinct(sIdx + 1, tIdx, s, t, dp);
        }

        return dp[sIdx][tIdx] = match + notMatch;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return findDistinct(0, 0, s, t, dp);
    }
};

/*
APPROACH:
We have two choices

1. If the character of both strings matches
  a. Consider the matched character
  b. Ignore the matched character

2. If they do not match then ignore

we need the sum of both of these conditions

*/
