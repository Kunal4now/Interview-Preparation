void Solution::rotate(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(a[j][i], a[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        reverse(a[i].begin(), a[i].end());
    }
}

/*
APPROACH:
=> Compute transpose and reverse every row
*/

/*
Time Complexity: O(N^2)
Space Complexity: O(1)
*/
