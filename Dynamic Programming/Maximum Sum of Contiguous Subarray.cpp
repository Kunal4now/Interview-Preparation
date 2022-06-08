int Solution::maxSubArray(const vector<int> &a) {
    int cur = a[0], max_so_far = a[0], n = a.size();
    for (int i = 1; i < n; i++) {
        cur = max(a[i], cur + a[i]);
        max_so_far = max(max_so_far, cur);
    }
    return max_so_far;
}
