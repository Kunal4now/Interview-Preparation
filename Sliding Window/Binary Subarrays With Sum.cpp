class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;

        int sum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (prefixCount.count(sum - goal)) {
                cnt += prefixCount[sum - goal];
            }
            prefixCount[sum]++;
        }

        return cnt;
    }
};

/*
APPROACH:
This problem cannot be solved with traditional two pointers because here the condition is not monotonic, so we cannot shrink our array until our condition satisfies again.
While encountering problems like these where we have to satisfy the condition with condition == target, we can use prefix sums.

Just keep the prefix sums that you encounter in a map and then on the way check if you have curr - goal with you

Time Complexity: O(N)
Space Complexity: O(N)
*/
