#include<bits/stdc++.h>
int Solution::maximumGap(const vector<int> &a) {
    int n = a.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, a[idx[i]] - a[idx[i - 1]]);
    }    
    
    return ans;
}

/*
APPROACH:
=> Just sort the array by indices and compute the gap
*/

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/
