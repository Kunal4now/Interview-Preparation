int Solution::repeatedNumber(const vector<int> &a) {
    int n = a.size();
    
    int slow = a[0];
    int fast = a[0];
    
    do {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);
    
    fast = a[0];
    while (slow != fast) {
        slow = a[slow];
        fast = a[fast];
    }
    
    return slow;
 }

/*
APPROACH: https://www.youtube.com/watch?v=32Ll35mhWg0
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
