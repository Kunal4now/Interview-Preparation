class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int bit = 0; bit < 32; bit++) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] & (1 << bit)) {
                    cnt++;
                }
            }
            if (cnt % 3) {
                ans += (1 << bit);
            }
        }
        
        return ans;
    }
};

/*
Time Complexity: O(32 * N)
Space Complexity: O(1)
*/

/*
APPROACH:
=> Since every number is repeating exactly 3 times, the bits in that number will also repeate atleast 3 times
=> If the bits are repeating in the multiple of 3, then these are the bits of the numbers that have appeared 3 times
=> If the bits are repeated in non multiple of 3, this means that this bit at this particular position is of the number which has appeared exactly once
=> We can keep track of the bits for every position and for every position where the bits are non multiple of 3, we can add that no. to the ans
*/
