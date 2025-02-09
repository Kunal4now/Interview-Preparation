class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 1e9, ans = 0;

        auto canEatBananas = [&](int k) {
            long long int total = 0, time = 0;
            for (int i = 0; i < n; i++) {
                time = ceil(piles[i] / k * 1.0);
                time += piles[i] % k != 0;
                total += time;
            }
            return total <= h;
        };

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEatBananas(mid)) {
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
APPROACH
Since there is monotonocity in the number of bananas to eat in an hour, we can just binary search on k

TIME COMPLEXITY: O(NLogN)
*/
