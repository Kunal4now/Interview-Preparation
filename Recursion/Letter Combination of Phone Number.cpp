class Solution {
public:
    map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t','u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    vector<string> ans;
    void helper(int i, string &digits, string str) {
        if (i == digits.size()) {
            ans.push_back(str);
            return;
        }
        
        for (auto &c: mp[digits[i]]) {
            helper(i + 1, digits, str + c);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return ans;
        }
        helper(0, digits, "");
        return ans;
    }
}; 
