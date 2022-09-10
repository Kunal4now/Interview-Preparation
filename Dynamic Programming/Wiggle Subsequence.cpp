class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n, 1), neg(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    pos[i] = max(pos[i], 1 + neg[j]);
                }
                else if (nums[i] < nums[j]) {
                    neg[i] = max(neg[i], 1 + pos[j]);
                }
            }
        }
        
        return max(pos.back(), neg.back());
    }
};

/*
APPROACH:
=> We can follow an LIS like approach
=> Maintain two arrays one for positive difference and one for negative difference
=> We will use positive for negative and vice versa
*/

/*
Time Complexity: O(N * N)
Space Complexity: O(N)
*/
