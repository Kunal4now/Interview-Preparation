class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, leftMax = 0, rightMax = 0, leftMaxIdx = -1, rightMaxIdx = -1;
        int ans = 0;
        while (left <= right) {
            if (height[left] > leftMax) {
                leftMax = height[left];
                leftMaxIdx = left;
            }
            if (height[right] > rightMax) {
                rightMax = height[right];
                rightMaxIdx = right;
            }

            ans = max(ans, (rightMaxIdx - leftMaxIdx) * min(rightMax, leftMax));
            if (leftMax < rightMax) left++;
            else right--;
        }

        return ans;
    }
};

/*
APPROACH:
Please watch trapping rain water solution first, this is the same problem but with just one change, we need to keep track of indexes of the max walls
and the rest is same

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/
