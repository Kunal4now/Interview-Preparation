class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n);
        partial_sum(nums.begin(), nums.end(), pref.begin(), [&](int &x, int &y) {
          return x * y;
        });

        vector<int> suf(n);
        partial_sum(nums.rbegin(), nums.rend(), suf.rbegin(), [&](int &x, int &y) {
          return x * y;
        });

        auto suffixSum = [&](int i, int j) {
          if (i >= n) return 1;
          return (j == n - 1 ? suf[i] : suf[i] - suf[j - 1]);
        };

        auto prefixSum = [&](int i, int j) {
          if (i < 0 or j < 0) return 1;
          return (i == 0 ? pref[j] : pref[j] - pref[i - 1]);
        };

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
          ans[i] = prefixSum(0, i - 1) * suffixSum(i + 1, n - 1);
        }

        return ans;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 0);
        pref[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] * nums[i];
        }

        int suffProduct = 1;
        for (int i = n - 1; i >= 1; i--) {
            pref[i] = pref[i - 1] * suffProduct;
            suffProduct *= nums[i];
        }

        pref[0] = suffProduct;

        return pref;
    }
};

/*
Approach:

1. Naive: Just create a prefix product and suffix product array and then for each element get the product of prefix and suffix
Time Complexity: O(N)
Space Complexity: O(N)


2. Optimal: Since we have to return an array, the return array iself would not be counted in space complexity so we can utilize it
  We just need to compute the prefix product array, and then iterate in reverse so that we will have suffix product in variable so we can use it compute our ans

Time Complexity: O(N)
Space Complexity: O(1)
*/
