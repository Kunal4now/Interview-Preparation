vector<int> Solution::slidingMaximum(const vector<int> &a, int w) {
    int n = a.size();
    
    vector<int> ans;
    deque<int> d;

    for (int i = 0; i < n; i++) {
        if (!d.empty() and d.front() == i - w) {
            d.pop_front();
        }
        while (!d.empty() and a[d.back()] < a[i]) {
            d.pop_back();
        }
        d.push_back(i);
        if (i >= w - 1) {
            ans.push_back(a[d.front()]);
        }
    }
    
    return ans;
}

/*
APPROACH: 
https://www.youtube.com/watch?v=CZQGRp93K4k&t=79s
*/

/*
Time Complexity: O(N)
Space Complexity: O(N);
*/
