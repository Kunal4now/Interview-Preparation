class Solution {
public:
    int dp[301];
    bool helper(int i, string &s, map<string, int> &mp) {
        if (i >= s.size()) {
            return true;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
        
        for (int j = i; j < s.size(); j++) {
            if (mp.find(s.substr(i, j - i + 1)) != mp.end()) {
                if (helper(j + 1, s, mp)) {
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        map<string, int> mp;
        for (auto &word: wordDict) {
            mp[word]++;
        }
        return helper(0, s, mp);
    }
};

/*
APPROACH:
=> We can create a map of the dictionary words that we have
=> After that, we can just iterate over the string and slice it at the point when we find that the particular substring is present in the map
*/
