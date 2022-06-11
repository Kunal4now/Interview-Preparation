bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    
    vector<array<int, 2>> interval(n);
    for (int i = 0; i < n; i++) {
        interval[i] = {arrive[i], depart[i]};
    }
    
    sort(interval.begin(), interval.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < n; i++) {
        if (pq.size() < K) {
            pq.push(interval[i][1]);
        }
        else if (interval[i][0] > pq.top()) {
            pq.pop();
            pq.push(interval[i][1]);
        }
        else {
            return false;
        }
    }
    
    return true;
}

/*
APPROACH:
=> First sort the intervals 
=> Then simulate the whole process by using a priority queue to keep track of all the departure times 
=> If the size of priority queue is less than K, then it means we can accomodate more guests
=> If we get the arrival time of the guest to be more than the smallest element of priority queue, that means the guest has left and need to be popped of from pq.
=> At any point if size of pq exceeds K, then the answer is false
*/

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/

// https://www.interviewbit.com/problems/hotel-bookings-possible/
