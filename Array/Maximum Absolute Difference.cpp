int Solution::maxArr(vector<int> &a) {
    int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < a.size(); i++) {
        max1 = max(max1, a[i] + i);
        min1 = min(min1, a[i] + i);

        max2 = max(max2, a[i] - i);
        min2 = min(min2, a[i] - i);
    }

    return max(max1 - min1, max2 - min2);
}

// https://www.interviewbit.com/problems/maximum-absolute-difference/

// APPROACH:
// If we expand the function f(i, j) = |A[i] - A[j]| + |i - j|, then the following cases will be formed

// 1. A[i] > A[j] , i > j => f(i, j) = (A[i] - A[j]) + (i-j) = (A[i]+i) - (A[j]+j)
// 2. A[i] < A[j] , i < j => f(i, j) = -(A[i] - A[j]) + -(i-j) = -(A[i]+i) + (A[j]+j) = - ( (A[i]+i) - (A[j]+j) )
// 3. A[i] > A[j] , i < j => f(i, j) = (A[i] - A[j]) + -(i-j) = (A[i]-i) - (A[j]-j)
// 4. A[i] < A[j] , i > j => f(i, j) = -(A[i] - A[j]) + (i-j) = -(A[i]-i) + (A[j]-j) = - ( (A[i]-i) - (A[j]-j) )
  
// 1, 2 and 3, 4 will give the same results so we will only need to check 2 conditons
