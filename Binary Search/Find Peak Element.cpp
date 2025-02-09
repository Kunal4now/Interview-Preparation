class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
    
        if (r == 0) {
            return 0;
        }
        
        if (nums[0] > nums[1]) {
            return 0;
        }
        
        if (nums[r] > nums[r - 1]) {
            return r;
        }
        
        while (l <= r) {
            int mid = (l + r) / 2;
            int left = (mid - 1 >= 0 ? nums[mid - 1] : -1e9);
            int right = (mid + 1 < nums.size() ? nums[mid + 1] : 1e9);
            if (nums[mid] > left and nums[mid] > right) {
                return mid;
            }
            else if (left > nums[mid]) {
                r = mid - 1;
            }
            else if (right > nums[mid]) {
                l = mid + 1;
            }
        }
        
        return 0;
    }
};

/*
Expliaiation : https://leetcode.com/problems/find-peak-element/discuss/1290642/Intuition-behind-conditions-or-Complete-Explanation-or-Diagram-or-Binary-Search
*/


/*
Second Try Feb 2025
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 2;
        if (n == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (nums[mid - 1] < nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};

/*
APPROACH
The array containing peak elements will have components in it which will follow sorted property, i.e, some part will be decreasing and some part will be increasing
We can use this property to eleminate the left or right half of the array
1. If the element left to the mid is smaller then that means that left part is increasing and peak is somewhere after mid i.e, in the right part
2. Else the peak is in the left half
3. Also we will be checking the peak element condition for the mid


TIME COMPLEXITY: O(LogN)
*/
