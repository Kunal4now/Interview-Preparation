class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right(n);
        stack<int> leftStack, rightStack;
        for (int i = 0; i < n; i++) {
          while (!leftStack.empty() and a[i] <= a[leftStack.top()]) {
            leftStack.pop();
          }
          left[i] = (leftStack.empty() ? -1 : leftStack.top());
          leftStack.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
          while (!rightStack.empty() and a[i] <= a[rightStack.top()]) {
            rightStack.pop();
          }
          right[i] = (rightStack.empty() ? n : rightStack.top());
          rightStack.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
          int width = right[i] - left[i] - 1;
          maxArea = max(maxArea, width * a[i]);
        }
        return maxArea;
    }
};

/*
APPROACH:
=> At every height a[i] we try to find the next smallest element in both the directions
=> the before the next element all the elements between them must be greater so we can try to expand till there
*/

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
