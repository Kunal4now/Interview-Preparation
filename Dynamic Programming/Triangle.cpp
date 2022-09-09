const int N = 1e3 + 10;
int dp[N][N];

int helper(int i, int j, vector<vector<int>> &a, int n) {
    if (i >= n or j > i) {
        return 0;
    }
    
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int down =  a[i][j] + helper(i + 1, j, a, n);
    int diag = a[i][j] + helper(i + 1, j + 1, a, n);
    
    return dp[i][j] = min(down, diag);
}

int minimumPathSum(vector<vector<int>>& a, int n){
    memset(dp, -1, sizeof(dp));
    
    return helper(0, 0, a, n);
}

/*
Time Complexity: O(N * M)
Space Complexity: O(N * N) + O(N) for stack space
*/


int minimumPathSum(vector<vector<int>>& a, int n){
    int dp[n + 1][n + 1];
    for (int i = 0; i < n; i++) {
        dp[n - 1][i] = a[n - 1][i];
    }
    
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            int down = a[i][j] + dp[i + 1][j];
            int diagonal = a[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down ,diagonal);
        }
    }
    
    return dp[0][0];
}

/*
APPROACH: 
=> We need to start from the ending point because the starting point is variable, so it makes sense to start from a fixed point
*/

/*
Time Complexity: O(N * N)
Space Complexity: O(N * N)
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = triangle[n - 1][i];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
            
        }
        
        return dp[0];
    }
};

/*
APPROACH:
=> We can just follow the usual space optimization technique
*/

/*
Time Complexity: O(N * N)
Space Complexity: O(N)
*/
