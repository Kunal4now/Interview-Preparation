/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 vector<Interval> merge(vector<Interval> &a) {
    int n = a.size();
    
    sort(a.begin(), a.end(), [&](const Interval x, const Interval y) {
        return x.start < y.start;
    });
    
    int mn = a[0].start, mx = a[0].end;
    
    vector<Interval> newInterval;
    for (int i = 1; i < n; i++) {
        if (a[i].start <= mx) {
            mx = max(mx, a[i].end);
        } else {
            newInterval.push_back(Interval(mn, mx));
            mn = a[i].start;
            mx = a[i].end;
        }
    }
    
    if (newInterval.size() == 0 or (newInterval.back().start != mn and newInterval.back().end != mx)) {
        newInterval.push_back(Interval(mn, mx));
    }
    
    return newInterval;
}
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    
    sort(intervals.begin(), intervals.end(), [&](const Interval x, const Interval y) {
        return x.start < y.start;
    });
    
    vector<Interval> ans = merge(intervals);
    
    return ans;
}

/*
APPROACH:
=> Insert the new Interval into the intervals vector
=> sort the interval by their start
=> Merge if there are any overlapping intervals
*/

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/
