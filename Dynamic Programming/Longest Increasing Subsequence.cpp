int Solution::lis(const vector<int> &a) {
    int n = a.size();
    
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

/*
Time Complexity: O(N * N)
Space Complexity: O(N)
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> tmp;
        tmp.push_back(a[0]);

        int len = 1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > tmp.back()) {
                tmp.push_back(a[i]);
                len++;
            } else {
                int idx = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
                tmp[idx] = a[i];
            }
        }

        return len;
    }
};

/*
APPROACH:
1. Instead of storing the LIS for every index, we can store what was the minimum number for which the LIS at this index ends
2. In this way we can maintain an auxilary array that would contain elements in the sorted manner
3. We can initialize the auxilary array with the first element and then do the following for iterations
    a) If the current element is greater than the last element of the aux array, we will simply push it into aux array since it is increasing.
    b) If the element is smaller, we will try to find the correct position for this element in the aux array, for this we can use lower_bound which will
       us the correct positon, we will replace the element with the current element on the index we got from lower bound.
4. The lenght of this aux array will give us the length of the LIS, but not the LIS itself
*/


/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/
