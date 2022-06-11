vector<Interval> Solution::merge(vector<Interval> &a) {
    int n = a.size();
    
    sort(a.begin(), a.end(), [&](const Interval x, const Interval y) {
        return x.start < y.start;
    });
    
    int mn = a[0].start, mx = a[0].end;
    
    bool unmerged = false;
    
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

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/
