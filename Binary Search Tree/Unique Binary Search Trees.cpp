class Solution {
public:
    int dp[20][20];
    int recurse(int n, int start, int end) {
        if (start >= end or start < 1 or end > n) {
            return 1;
        }
        if (dp[start][end] != -1) {
            return dp[start][end];
        }
        int cnt = 0;
        for (int i = start; i <= end; i++) {
            cnt += recurse(n, start, i - 1) * recurse(n, i + 1, end);
        }
        return dp[start][end] = cnt;
    }
    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));
        return recurse(n, 1, n);
    }
};

/*
APPROACH:
=> We can observe that the total number of unique BSTs is:
      total no. of unique BSTs on the left of root * total no. of unique BSTs on the right of root
=> So we can recursively build our solution, and for the base case if any of the pointer goes out of bound or the pointers cross each other
   the the unique BSTs would be 1
*/
