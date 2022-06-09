#include <bits/stdc++.h>
int Solution::solve(int n, vector<int> &a) {
    int sum = accumulate(a.begin(), a.end(), 0);

    if (sum % 3 != 0) {
        return 0;
    }	    

    vector<int> pref(int(a.size()));

    n = a.size();
    partial_sum(a.begin(), a.end(), pref.begin());

    auto get = [&](int l, int r) {
        if (l < 0 or r < 0) return 0;
        return (l == 0 ? pref[r] : pref[r] - pref[l - 1]);
    };

    vector<int> prefix, suffix;

    for (int i = 0; i < n; i++) {
        if (pref[i] == sum / 3) {
            prefix.push_back(i);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (get(i, n - 1) == sum / 3) {
            suffix.push_back(i);
        }
    }

    reverse(suffix.begin(), suffix.end());

    int suffix_sz = suffix.size();
    int cnt = 0;
    for (int i = 0; i < prefix.size(); i++) {
        int idx = upper_bound(suffix.begin(), suffix.end(), prefix[i] + 1) - suffix.begin();
        if (idx < suffix_sz && suffix[idx] > prefix[i]) {
            cnt += suffix_sz - idx;
        }
    }

    return cnt;
}

/*
APPROACH:
=> If the sum of whole array is divisible by 3, then only we can partition it into 3 arrays with equal sum
=> Sum of each part of array must be sum / 3.
=> We can maintain the indices wherever we get the prefix sum and suffix sum to be sum / 3 in two separate arrays
=> Once we have indices, we can iterate over prefix indices and binary search the suffix index. We do not need to check the sum of middle elements because if the
   sum of prefix and suffix is sum / 3 then the middle elements must bt sum / 3.
*/
