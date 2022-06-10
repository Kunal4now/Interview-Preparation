int Solution::solve(vector<int> &a, int b) {
    int n = a.size(), cnt = 0, i = 0;
    while (i < n) {
        bool flag = false;
        int l = i - b + 1, r = i + b - 1; // Loop through every range we get
        for (int j = r; j >= l; j--) { // Loop in reverse so that we select the farthest bulb
            if (a[j]) { // If we find a bulb we can turn on, we will take it
                cnt++;
                i = b + j; // we will set i to (b + j) since all the bulbs before it have already been covered
                flag = true;
                break;
            }
        }
        if (!flag) { // If we don't find any valid bulb that covers the range we return -1
            return -1;
        }
    }
    return cnt;
}

/*
Time Complexity: O(N)
Spaec Complexity: O(1)
*/
