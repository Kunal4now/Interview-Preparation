vector<int> Solution::getRow(int n) {
    vector<int> a(n + 1);
	a[0] = 1;
	int tmp = 1;
	for (int i = 1; i <= n; i++) {
		tmp = tmp * (n - i + 1) / (i);
		a[i] = tmp;
	}
    return a;
}

/*
APPROACH:
=> There is a simple formula for every row
=> for row i tmp = tmp * (n - i + 1) / (i); 
=> E.g.: n = 3
=> 1,  1 * (3 - 1 + 1) / 1 = 3, 3 * (3 - 2 + 1) / 2
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
