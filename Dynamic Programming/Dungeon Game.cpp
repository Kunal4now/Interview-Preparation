class Solution {
public:
    int dp[201][201];
    int helper(int i, int j, vector<vector<int>> &dungeon) {
        if (i >= dungeon.size() or j >= dungeon[0].size()) {
            return INT_MAX;
        }
        
        if (i == dungeon.size() - 1 and j == dungeon[0].size() - 1) {
            return (dungeon[i][j] <= 0 ? 1 + (-dungeon[i][j]) : 1);
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int right = helper(i, j + 1, dungeon);
        int down = helper(i + 1, j, dungeon);
        
        int minRequired = min(right, down) - dungeon[i][j];
        
        return dp[i][j] = (minRequired <= 0 ? 1 : minRequired);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, dungeon);
    }
};

/*
APPROACH:
=> Since the health of the knight cannot be <= 0 at any point, even if there are no demons we still need to have health atleas 1
=> If any cell has a negative value (i.e, there is a demon in that cell) we need atleast -dungeon[i][j] health to make it equal to the demon and add 1 to it to make it
   larger
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M) + O(N + M)
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 1e9));
        
        dp[n][m - 1] = 1;
        dp[n - 1][m] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int minRequired = min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j];
                dp[i][j] = (minRequired <= 0 ? 1 : minRequired);
            }
        }
        
        return dp[0][0];
    }
};

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/
