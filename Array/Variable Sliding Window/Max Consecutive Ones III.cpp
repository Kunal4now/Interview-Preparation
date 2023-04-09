class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, maxConsecutiveOnes = 0, flips = 0;
        
        while (right < nums.size()) {
            if (nums[right] == 0) {
                flips++;
            }
            while (flips > k) {
                if (nums[left] == 0) {
                    flips--;
                }
                left++;
            }
            maxConsecutiveOnes = max(maxConsecutiveOnes, right - left + 1);
            right++;
        }
        
        return maxConsecutiveOnes;
    }
};

/*
APROACH:
=> Expand the window by using all the flips.
=> Once you run out of the flips, simply slide the window from left untill you have more flips to use
=> at each stage maintain the max answer by using the lenght of the current window (right - left + 1)
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
