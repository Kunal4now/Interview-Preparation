vector<vector<int> > Solution::solve(int n) {
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        triangle[i][0] = 1, triangle[i].back() = 1;
        for (int j = 1; j < i; j++) {
            int x = (j - 1 >= 0 ? triangle[i - 1][j - 1] : 0);
            int y = (j + 1 <= i ? triangle[i - 1][j] : 0);
            triangle[i][j] = x + y;
        }
    }
    return triangle;
}

/*
Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/
