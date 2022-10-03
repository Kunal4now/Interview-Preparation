class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) {
            vector<vector<int>> ans;
            ans.push_back(newInterval);
            return ans;
        }
        
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [&](const auto &i1, const auto &i2) {
            return i1[0] < i2[0];
        });
        
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> newIntervals;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            }
            else {
                newIntervals.push_back({start, end});
                start = intervals[i][0], end = intervals[i][1];
            }
        }
        
        if (newIntervals.size() == 0 or (start != newIntervals.back()[0] and end != newIntervals.back()[1])) {
            newIntervals.push_back({start, end});
        }
        
        return newIntervals;
    }
};

/*
APPROACH:
=> Just insert the newInterval into the intervals and sort them
=> merge all overlapping intervals and return the ans
*/

/*
Time Complexity: O(NLogN)
Space Complexity: O(N)
*/
