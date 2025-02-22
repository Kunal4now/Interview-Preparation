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
    int trap(vector<int>& a) {
        int n = a.size();

        int left = 0, leftMax = 0, right = n - 1, rightMax = 0;
        int water = 0;
        while (left <= right) {
            leftMax = max(leftMax, a[left]);
            rightMax = max(rightMax, a[right]);
            water += max(min(leftMax, rightMax) - a[left], 0);
            water += max(min(leftMax, rightMax) - a[right], 0);
            if (leftMax < rightMax) left++;
            else right--;
        }

        return water;
    }
};      

/*
APPROACH:
Since we are calculating the total water trapped for each index, we were previously maintaining the prefix and suffix max arrays, since these can be calculated on
the fly we can adapt a two pointer approach that would calculate leftMax and rightMax in one go, and the logic to move the left and right pointers would be
if leftMax is smaller than rightMax, since the trapped water is dictated using min(leftMax, rightMax) we'll need to maximize the smaller one so we will be moving
the smaller max pointer.

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)
*/
