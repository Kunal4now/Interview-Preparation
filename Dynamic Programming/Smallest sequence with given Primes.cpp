vector<int> Solution::solve(int A, int B, int C, int D) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(A);
    minHeap.push(B);
    minHeap.push(C);
    map<int, int> mp;

    vector<int> results;
    while (results.size() < D) {
        int next = minHeap.top();
        minHeap.pop();

        if (mp.find(next) == mp.end()) {
            results.push_back(next);
            minHeap.push(next * A);
            minHeap.push(next * B);
            minHeap.push(next * C);
            mp[next]++;
        }
    }
    return results;
}

/*
APPROACH:
=> At every point we are multiplying with one of the three numbers
=> We can simulate this process by using modified BFS / Dijkstras and take the minimim D elements
*/

/*
Time Compleixty: O(D * Log D)
Space Complexity: O(D)
*/
