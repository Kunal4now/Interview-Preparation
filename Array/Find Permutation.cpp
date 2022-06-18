vector<int> Solution::findPerm(const string A, int n) {
    vector<int> a(n);
    
    int l = 1, r = n;
    
    int idx = 0;
    for (auto &x: A) {
        if (x == 'I') {
            a[idx++] = l;
            l++;
        } else {
            a[idx++] = r;
            r--;
        }
    }
  
    a[idx] = l;
    return a;
}

/*
APPROACH:
=> At every point we need to choose either l or r
=> if s[i] = I, then we will place l, otherwise r
=> and increase/decrease them accordingly
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
