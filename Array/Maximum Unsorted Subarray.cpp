vector<int> Solution::subUnsort(vector<int> &a) {
    int n = a.size();
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if (a[i] == a[j]) {
            return i < j;
        } else {
            return a[i] < a[j];
        }
    });

    vector<int> range;
    int i = 0;
    while (i < n and idx[i] == i) {
        i++;
    }
    
    int j = n - 1;
    while (j > i and idx[j] == j) {
        j--;
    }
    
    if (idx[i] != i and idx[j] != j and i < j) {
        range.push_back(i);
        range.push_back(j);
        return range;
    }
    
    range.push_back(-1);
    return range;
}

/*
APPROACH:
=> Sort the indices of array in such a way so that the indices of the same elements also remain in order
*/

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/
