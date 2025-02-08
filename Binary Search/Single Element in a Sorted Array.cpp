class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            else if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

/*
APPROACH
Since the array is sorted, we can think of a binary search solution, we just need to think of the condition to eliminate the either of the halves
1 1 2 2 3 3 4 4 |5| 6 6 7 7
e o e o e o e o  e  o e o e

If you notice just before the single element all same elements appear in (even, odd) manner and after (odd, even), this can be the elimination condition
if your mid is even and mid + 1 is same then you are on the right half
if your mid is odd and mid - 1 is same then you are on the left half
if your mid does not match with mid - 1 and mid + 1 then you got the answer

The starting if conditions are placed to handle corner cases of the array

TIME COMPLEXITY: O(LogN)
*/
