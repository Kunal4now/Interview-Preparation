class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
            if (counts[c] > (n + 1) / 2) {
                return "";
            }
        }

        priority_queue<pair<int, char>> pq;
        for (auto& [c, freq] : counts) {
            pq.push({freq, c});
        }
        
        string result = "";
        
        while (pq.size() >= 2) {
            auto [freq1, char1] = pq.top(); pq.pop();
            auto [freq2, char2] = pq.top(); pq.pop();
            
            result += char1;
            result += char2;
            
            if (--freq1 > 0) pq.push({freq1, char1});
            if (--freq2 > 0) pq.push({freq2, char2});
        }
        
        if (!pq.empty()) {
            auto [freq, c] = pq.top();
            if (freq > 1) return "";
            result += c;
        }
        
        return result;
    }
};

/*
APPROACH:

We can maintain a priority queue of frequency and we can just pick the characters alternatively
*/
