#include<stack>
vector<int> findSpans(vector<int> &a) {
    int n = a.size();
    stack<int> s;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() and a[i] >= a[s.top()]) {
            s.pop();
        }
        if (!s.empty()) {
            ans[i] = i - s.top();
        } else {
            ans[i] = i + 1;
        }
        s.push(i);
    }
    return ans;
}

/*
APPROACH:
=> We need to find consecutive smaller stock prices to the left of the current stock price
=> Instead of finding consecutive smaller prices, we can find next greater price to the left and all the elements between two will be consecutive smaller
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/

