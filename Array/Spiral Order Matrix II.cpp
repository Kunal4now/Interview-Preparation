vector<vector<int> > Solution::generateMatrix(int n) {
    vector<vector<int>> a(n, vector<int> (n));
    int cnt = 1;
    int top = 0, left = 0, right = n - 1, dir = 0, down = n - 1;
    while (top <= down and left <= right) {
      if (dir == 0) {
        for (int i = left; i <= right; i++) {
          a[top][i] = cnt++;
        }
        dir = 1;
        top++;
      }
      if (dir == 1) {
        for (int i = top; i <= down; i++) {
          a[i][right] = cnt++;
        }
        dir = 2;
        right--;
      }
      if (dir == 2) {
        for (int i = right; i >= left; i--) {
          a[down][i] = cnt++;
        }
        dir = 3;
        down--;
      }
      if (dir == 3) {
        for (int i = down; i >= top; i--) {
          a[i][left] = cnt++;
        }
        dir = 0;
        left++;
      }
    }
    return a;
}

/*
APPROACH:
=> Maintain the foll. variables
=> 1. top = points to top row initially
=> 2. down = points to the bottom row initially
=> 3. left = points to the leftmost element of first row initially
=> 4. right = points to the rightmost elemnt of first row initially
=> 5. dir = direction of traversal(0 => left to right, 1 => top to down, 2 => right to left, 3 => down to top)
=> iterate in all directions one by one and update the pointers accordingly
*/

/*
Time Complexity: O(N * N)
Space Compelxity: O(N * N)
*/
