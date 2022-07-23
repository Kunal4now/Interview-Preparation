class Solution {
public:
    bool is_equal(string &s, string &t) {
        int n = s.size(), m = t.size();
        if (m != n + 1) {
            return false;
        }
        int i = 0, j = 0;
        while (j < m) {
            if (s[i] == t[j]) {
                i++, j++;
            } else {
                j++;
            }
        }
        return i == n and j == m;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&](string &s1, string &s2) {
            return s1.size() < s2.size();
        });
        
        int mx = 1;
        
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (is_equal(words[j], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return mx;
    }
};

/*
Time Complexity: O(N ^ 2 * L)
Space Complexity: O(N)
*/
