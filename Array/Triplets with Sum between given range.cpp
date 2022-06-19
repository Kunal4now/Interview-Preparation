int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<double> a(n);
    
    for (int i = 0; i < n; i++) {
        a[i] = stod(A[i]);
    }
    
    sort(a.begin(), a.end());
    
    int i = 0, j = n - 1;
    while (j - i >= 2) {
        double val = a[i] + a[i + 1] + a[j];
        if (val >= 2) {
            j--;
        } 
        else if (val < 1) {
            i++;
        }
        else {
            return 1;
        }
    }
    return 0;
}

/*
APPROACH:
=> Sort the array and use two pointers
*/

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/
