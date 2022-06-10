int Solution::solve(vector<int> &a) {
    sort(a.begin(), a.end());
    
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int idx = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
        if (a[i] == n - idx) {
            return 1;
        }
    }
    
    return -1;
}

// https://www.interviewbit.com/problems/noble-integer/
