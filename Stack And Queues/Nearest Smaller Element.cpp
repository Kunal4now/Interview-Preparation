vector<int> Solution::prevSmaller(vector<int> &a) {
    int n = a.size();
    
    stack<int> s;
    
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        while (!s.empty() and s.top() >= a[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans.push_back(-1);
        } else {
            ans.push_back(s.top());
        }
        s.push(a[i]);
    }
    
    return ans;
}

/*
APPROACH:
=> if stack is not empty, then pop its elements until s.top() >= a[i] because they don't matter now
=> after popping, the top of that element will be the nearest smallest
=> and push a[i] to the stack
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
