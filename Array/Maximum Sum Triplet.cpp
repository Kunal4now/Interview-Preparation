#include<bits/stdc++.h>
int Solution::solve(vector<int> &a) {
    int n = a.size();

    vector<int> suf(n);
    partial_sum(a.rbegin(), a.rend(), suf.rbegin(), [&](int x, int y) {
        return max(x, y);
    });

    int maxSum = 0;
    set<int> s; s.insert(a[0]);

    for (int i = 1; i < n - 1; i++) {
        auto left = s.lower_bound(a[i]);
        --left;
        if (left != s.end() and *left  < a[i] and a[i] < suf[i + 1]) {
            maxSum = max(maxSum, *left + a[i] + suf[i + 1]);
        }
        s.insert(a[i]);
    }

    return maxSum;
}

// https://www.interviewbit.com/problems/maximum-area-of-triangle/
