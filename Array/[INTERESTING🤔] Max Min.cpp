pair<int, int> findMinMax(int start, int end, vector<int> &A) {
    if (start == end) {
        return make_pair(A[start], A[end]);
    }
    
    int mid = (start + end) / 2;
    
    auto left = findMinMax(start, mid, A);
    auto right = findMinMax(mid + 1, end, A);
    
    int mn = min(left.first, right.first);
    int mx = max(left.second, right.second);
    
    return make_pair(mn, mx);
}

int Solution::solve(vector<int> &A) {
    auto ans = findMinMax(0, A.size() - 1, A);
    return ans.first + ans.second;
}


/*
INITIAL THOUGHTS:
=> Just sort it lol
*/

/*
 APPROACH:
 => If we iterate over every element one by one then, there will be 2N comparisons, N for max element and N for min.
 => To reduce this, we can follow a divide and conquer approach
 => Divide the array into two halves and search for min max in both of them recursively
 => Total no. of comparisons in this approach will be 3N / 2 which is better than 2N
*/
