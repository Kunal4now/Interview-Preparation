vector<bool> subsetSumToK(int n, int k, vector<int> &a) {
    vector<bool> cur(k + 1, false), prev(k + 1, false);
    
    prev[0] = cur[0] = true;
    if (a[0] <= k) {
        prev[a[0]] = true; 
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool take = false;
            if (j >= a[i]) {
                take = prev[j - a[i]];
            }
            bool notTake = prev[j];
            cur[j] = take or notTake;
        }
        prev = cur;
    }
    
    return cur;
}

int minSubsetSumDifference(vector<int>& a, int n) {
    int sum = accumulate(a.begin(), a.end(), 0);
    vector<bool> subset = subsetSumToK(n, sum, a);
    
    int mn = 1e9;
    for (int i = 0; i <= sum / 2 ; i++) {
        if (subset[i]) {
            mn = min(mn, abs((sum - i) - i));
        }
    }
    
    return mn;
}

/*
Time Complexity: O(N * SUM)
Space Complexity: O(SUM)
*/
