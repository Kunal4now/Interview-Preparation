vector<int> Solution::nextPermutation(vector<int> &a) {
    int idx1 = -1;
    int n = a.size();
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            idx1 = i;
            break;
        }
    }
    
    if (idx1 == -1) {
        reverse(a.begin(), a.end());
        return a;
    }
    
    int idx2 = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > a[idx1]) {
            idx2 = i;
            break;
        }
    }
    
    swap(a[idx1], a[idx2]);
    
    reverse(a.begin() + idx1 + 1, a.end());
    
    return a;
}

/*
APPROACH: https://www.youtube.com/watch?v=LuLCLgMElus
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
