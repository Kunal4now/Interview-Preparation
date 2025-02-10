class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low + k;
    }

      /*
          7 11
          low = 4
          high = 3
          low = high + 1
          7 = arr[high]
          missing = arr[high] - (mid + 1) = 3
          something = k - missing = k - arr[high] + missing + 1
          ans = arr[high] + k - missing
          ans = arr[high] + k - arr[high] + high + 1
          ans = high + k + 1
          ans = low + k
      */
};

/*
APPROACH
Since the numbers are unique, we can find for each index how many elements are missing
for example
2 3 4 7 11

idx = 0, it should be 1 but it is 2 at its position so the missing numbers are 2 - (index + 1) = 1
idx = 3, it should be 4 but it is 7 at its position so the missing numbers are 7 - (index + 1) = 3

in the end the array would look like
1 1 1 3 6

This is monotonic and it will give us two index between which our answer will lie
in the end of the binary search both of the bounds will cross and high will become  less than low

in the above case low will be 4 and high will be 3

once we get this the calculations for ans are given int above code


Space Complexity: O(LogN)
*/
