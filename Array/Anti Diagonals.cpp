vector<vector<int> > Solution::diagonal(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    int sz = n + m - 1;
    vector<vector<int>> ans(sz);

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int x = 0, y = i;
        while (x < m and y >= 0) {
            ans[cnt].push_back(a[x][y]);
            x++, y--;
        }
        cnt++;
    }
    
    for (int i = 1; i < n; i++) {
        int x = i, y = m - 1;
        while (x < n and y >= 0) {
            if (x < n and y >= 0) {
                ans[cnt].push_back(a[x][y]);
            }
            x++, y--;
        }
        cnt++;
    }
    
    return ans;
}

/*
APPROACH:
=> Just look at the indices and simulate the process
*/

/*
Time Complexity: O(N * N)
Space Complexity: O(N * N)
*/
