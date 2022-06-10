vector<int> Solution::flip(string s) {
    int n = s.size();

    int one = 0, zero = 0, l = 0, r = 0, max_ending_here = 0, max_so_far = INT_MIN, left = -1, right = -1;
    for (int i = 0; i < n; i++) {
        max_ending_here += (s[i] == '0' ? 1 : -1);
        if (max_ending_here < 0) {
            l = i + 1;
            max_ending_here = 0;
        }
        else if (max_ending_here > max_so_far) {
            r = i;
            max_so_far = max_ending_here;
            left = l, right = r;
        }
    }
    
    vector<int> range;
    if (max_so_far <= 0) {
        return range;
    } else {
        range.push_back(left + 1);
        range.push_back(right + 1);
        return range;
    }
}

/*
APPROACH:

Note what is the net change in number of 1s in string S when we flip bits of string S.
Say it has A 0s and B 1s. Eventually, there are B 0s and A 1s.

So, number of 1s increase by A - B. We want to choose a subarray which maximises this. 
Note, if we change 1s to -1 and change 0 to 1, then sum of values will give us A - B. 
Then, we have to find a subarray with maximum sum, which can be done via Kadane’s Algorithm.
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/

// https://www.interviewbit.com/problems/flip/
