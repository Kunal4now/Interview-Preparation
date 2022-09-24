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
