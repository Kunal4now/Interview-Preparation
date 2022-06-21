string Solution::solve(string A) {
    queue<char> q; q.push(A[0]);
    map<char, int> mp;
    string ans = "";
    
    for (auto &c: A) {
        mp[c]++;
        q.push(c);
        while (!q.empty() and mp[q.front()] > 1) {
            q.pop();
        }
        if (!q.empty()) {
            ans += q.front();
        } else {
            ans += '#';
        }
    }
    
    return ans;
}

/*
Time Complexity: O(NlogN)
Space Compleixty: O(N)
*/

string Solution::solve(string A) {
    queue<char> q; q.push(A[0]);
    vector<int> alpha(26,0);
    string ans = "";
    
    for (auto &c: A) {
        alpha[c - 'a']++;
        q.push(c);
        while (!q.empty() and alpha[q.front() - 'a'] > 1) {
            q.pop();
        }
        if (!q.empty()) {
            ans += q.front();
        } else {
            ans += '#';
        }
    }
    
    return ans;
}

/*
Time Complexity: O(N)
Space Complexity: O(26)
*/
