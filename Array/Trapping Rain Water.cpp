class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();

        vector<int> prefix(n), suffix(n);
        prefix[0] = a[0], suffix[n - 1] = a[n - 1];

        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], a[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], a[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            water += max(min(prefix[i], suffix[i]) - a[i], 0);
        }

        return water;
    }
};      

/*
APPROACH:
We need to maintain a prefix and suffix max arrays and to calculate water trapped at each index we need to take their minimum for each index and remove the bar at
at that index (a[i])

TIME COMPLEXTIY: O(N)
SPACE COMPLEXITY: O(N)
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int leftMax = height[0], rightMax = height[n - 1];
        int left = 0, right = n - 1;

        int ans = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                ans += max(0, leftMax - height[left]);
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                ans += max(0, rightMax - height[right]);
                right--;
            }
        }

        return ans;
    }
};    

/*
APPROACH:
To optimize the prefix sum approach we can note one observation if (height[left] <= height[right]) this gives us assurance that we do not
need to check the rightMax because it is already smaller than height[right] so we can just get away by comparing it with the leftMax
we need to do the same thing with the rightMax

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/
