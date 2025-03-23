class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char &ch: t) {
            mp[ch]++;
        }

        int n = s.size();

        int i = 0, j = 0, cnt = t.size(), mn = INT_MAX, start = 0;
        while (i < s.size() and j < s.size()) {
            if (mp[s[j]] > 0) {
                cnt--;
            }
            mp[s[j]]--;
            j++;
            while(cnt == 0) {
                if (j - i < mn) {
                    start = i;
                    mn = j - i;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    cnt++;
                }
                i++;
            }
        }

        if (mn != INT_MAX) {
            return s.substr(start, mn);
        }

        return "";
    }
};

/*
APPROACH:
1. We need to first expand our window such that it contians all of the characters of t.
2. Once we satisfy the above condition, we need to shrink our window from front.
3. While shrinking we need to keep the minimum size found with as as well as on which index it started.
4. Once done, just return the substring of length minimum.
*/
