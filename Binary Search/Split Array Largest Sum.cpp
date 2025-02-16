class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        auto check = [&](int minSum) {
            int sum = 0, split = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (sum + nums[i] > minSum) {
                    split++;
                    sum = nums[i];
                } else {
                    sum += nums[i];
                }
            }

            return split <= m;
        };

        int low = *max_element(nums.begin(), nums.end()), high = 1e9, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};


/*
APPROACH:
We need to minimize the max sum each one of the k partitions can have, we can just search over that maximum sum using binary search and try to partition the array 

Time Complexity: O(NLogN)
*/
