class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_so_far = nums[0], min_so_far = nums[0], max_here = nums[0], min_here = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(max_here, min_here);
            }
            max_here = max(nums[i], nums[i] * max_here);
            min_here = min(nums[i], nums[i] * min_here);
            
            max_so_far = max(max_so_far, max_here);
        }
        return max_so_far;
    }
};

/*
APPROACH:
=> This is a variation of Kadane's Algorithm
=> We keep track of min and max product so far
=> If we encounter a negative element then to maxize them sum we need to muitiply it with another negative no. which is min_here, thats why we swap min_here and max_here
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
