class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }        

        return ans;
    }
};

/*
APPROACH
Since we know the property of a rotated sorted array, which is in a rotated sorted array if you calculate the mid, one of the halves of the broken down arrays
would be sorted.
Just take the min element of the sorted halves and you'll have your answer

TIME COMPLEXITY: O(LogN)
*/
