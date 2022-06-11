int maximumGap(const vector<int> &a) {
    int n = a.size();

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    int max_idx = -1;
    vector<int> suf(n);
    for (int i = n - 1; i >= 0; i--) {
        max_idx = max(max_idx, idx[i]);
        suf[i] = max_idx;
    }

    int mx_diff = INT_MIN;
    for (int i = 0; i < n; i++) {
        mx_diff = max(mx_diff, suf[i] - idx[i]);
    }
    
    return mx_diff;
}

/*
APPROACH:
=> Sort the indices of the array
=> Create a suffix array which contains the maximum index at i
=> Simply loop over the sorted indices and for every index idx[i] store the max diff (suf[i] - idx[i])
*/

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/
