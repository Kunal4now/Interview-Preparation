#include"bits/stdc++.h"
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    vector<int> a = A;
    int n = a.size();
    long long tot = accumulate(a.begin(), a.end(), 0LL);

    long long sum = (1LL * n) * ((1LL * n) + 1LL) / 2LL;

    long long totSq = 0;
    for (int i = 0; i < n; i++) {
        totSq += (1LL * a[i]) * (1LL * a[i]);
    }

    long long sumSq = 1LL * ((1LL * n) * ((1LL * n) + 1) * (2 * (1LL * n) + 1)) / 6;

    long long y = (totSq - sumSq) / (tot - sum);

    long long x = tot - sum;

    long long repeate = (x + y) / 2LL;

    long long missing = repeate - x;
    
    vector<int> ans = {repeate, missing};
    return ans;
}

/*
APPROACH:
=> Sum(Actual) = Sum(1...N) + A - B

=> Sum(Actual) - Sum(1...N) = A - B --- eq(1)

=> Sum(Actual Squares) = Sum(1^2 ... N^2) + A^2 - B^2

=> Sum(Actual Squares) - Sum(1^2 ... N^2) = (A - B)(A + B) = (Sum(Actual) - Sum(1...N))( A + B) {put (A - B) as eq(1)

sove these two equations and you'll get the answer
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
