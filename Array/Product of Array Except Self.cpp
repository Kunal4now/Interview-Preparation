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
