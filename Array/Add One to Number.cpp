vector<int> Solution::plusOne(vector<int> &a) {
    int n = a.size();
    int ptr = 0;
    while (a[ptr] == 0 and ptr < n) ptr++;
    
    int sz = max(1, n - ptr);
    vector<int> res(sz);
    
    int carry = 0, val = 0;

    a[n - 1]++;
    res[sz - 1] = a[n - 1];
    for (int i = n - 1; i >= ptr; i--) {
        val  = (a[i] + carry) % 10;
        carry = (a[i] + carry) / 10;
        a[i] = val;
        res[i - ptr] = val;
    }
    
    if (carry) {
        res.insert(res.begin() + ptr, carry);
    }
    
    return res;
}
