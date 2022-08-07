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
    
    unordered_map<int, vector<vector<string>>> mp;
    
    vector<vector<string>> dp(int i, string &s) {
        if (i == s.size()) {
            return vector<vector<string>>();
        }
        
        if (mp.count(i)) {
            return mp[i];
        }
        
        vector<vector<string>> ans;
        
        for (int j = i; j < s.size(); j++) {
            if (is_palindrome(i, j, s)) {
                vector<vector<string>> res = dp(j + 1, s);
                string substring = s.substr(i, j - i + 1);
                for (auto &x: res) {
                    x.insert(x.begin(), substring);
                }
                
                if (res.empty()) {
                    res.push_back({substring});
                }
                
                for (auto &x: res) {
                    ans.push_back(x);
                }
            }
        }
        
        return mp[i] = ans;
    }
    vector<vector<string>> partition(string s) {
        return dp(0, s);
    }
};

/*
APPROACH:
=> We basically partition at an index where we find that string from i to j is palindrome
=> after partitioning we call to get the all palindromes from j + 1 to N
=> Since the current string is also a palindrome, we just append this string in all the palindrome partitions we have found from j + 1
*/

/*
Time Complexity: N * 2 ^ N
*/

/*
OPTIMIZATION:
=> We can memoize the already computed partitions into a DS like a map
*/
