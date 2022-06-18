#include "bits/stdc++.h"
int Solution::perfectPeak(vector<int> &a) {
    int n = a.size();

    vector<int> suf(n);
	partial_sum(a.rbegin(), a.rend(), suf.rbegin(), [&](int x, int y) {
		return min(x, y);
	});
    
    int mx = a[0], ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > mx and a[i] < suf[i + 1]) {
            ans = 1;
        }
        mx = max(mx, a[i]);
    }
    
    return ans;
}


/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
