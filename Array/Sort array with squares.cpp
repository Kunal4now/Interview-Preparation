vector<int> Solution::solve(vector<int> &a) {
    int n = a.size();
    
    vector<int> tmp1, tmp2;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            tmp1.push_back(a[i] * a[i]);
        } else {
            tmp2.push_back(a[i] * a[i]);
        }
    }
    
    reverse(tmp1.begin(), tmp1.end());
    
    vector<int> ans;
    int i = 0, j = 0;
    while (i < tmp1.size() and j < tmp2.size()) {
        if (tmp1[i] <= tmp2[j]) {
            ans.push_back(tmp1[i]);
            i++;
        }
        else if (tmp1[i] >= tmp2[j]) {
            ans.push_back(tmp2[j]);
            j++;
        } else {
            i++, j++;
        }
    }
    
    while (i < tmp1.size()) {
        ans.push_back(tmp1[i]);
        i++;
    }
    
    while (j < tmp2.size()) {
        ans.push_back(tmp2[j]);
        j++;
    }
    
    return ans;
}
