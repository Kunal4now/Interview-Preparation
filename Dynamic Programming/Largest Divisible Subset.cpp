class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
    
        vector<int> hash(n);
        iota(hash.begin(), hash.end(), 0);
        
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] % nums[i] == 0 or nums[i] % nums[j] == 0 and 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
        }
        
        int idx = max_element(dp.begin(), dp.end()) - dp.begin();
        
        vector<int> seq;
        seq.push_back(nums[idx]);
        while (idx != hash[idx]) {
            idx = hash[idx];
            seq.push_back(nums[idx]);
        }
        
        reverse(seq.begin(), seq.end());
        
        return seq;
    }
};

/*
APPROACH:
=> To compute the largest divisible subset the procedure is similar to LIS
=> To print it, while calculating LDS if we get a bigger sequence we will store that index in our hash array
=> After calculating this hash array we will start backtracking the indices from the index where we have got the largest divisble subset
*/

/*
Time Complexity: O(N * N)
Space Complexity: O(N)
*/
