class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> tmp(n + 1, vector<int> (m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                tmp[i][j] = matrix[i - 1][j - 1];
                if (matrix[i - 1][j - 1] == 0) {
                    tmp[0][j] = 1, tmp[i][0] = 1;
                }
            }
        }
    
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j++) {
                if (tmp[i][0] or tmp[0][j]) {
                    tmp[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                matrix[i][j] = tmp[i + 1][j + 1];
            }
        }
        
        return;
    }
};

/*
APPROACH:
=> Create a matrix of n + 1 and m + 1 size
=> The zeroth row and column of this tmp matrix will work as a marker that states that this row and col contains a zero
=> Fill the tmp matrix with original matrix from first row
=> Traverse the matrix normally and check whether that row and col has a zero in it or not (tmp[i][0] or tmp[0][j]) and change elements to zero accordingly
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(N * M}
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1, col[j] = 1;
                }
            }
        } 
         
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] or col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        return;
    }
};

/*
APPROACH:
=> Maintain two arrays to keep track of the zeroes and mark them in their respective row array and column array
=> Iterate over them one by one and set the whole row / colum to zero wherever it is marked
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(N + M)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), col0 = 1;
        for (int i = 0; i < n; i++) {
            if (a[i][0] == 0) col0 = 0; //check if the first element is zero or not because we will have to make it zero in the last because we will store markings in it
            for (int j = 1; j < m; j++) { //start from 1 to prevent disturbing the row markings
                if (a[i][j] == 0) {
                    a[i][0] = a[0][j] = 0; //mark the row and column
                }
            }
        }
        
        for (int i = n - 1; i >= 0; i--) { //iterate from reverse to not disturb other elements
            for (int j = m - 1; j >= 1; j--) {
                if (a[i][0] == 0 or a[0][j] == 0) {
                    a[i][j] = 0;
                }
            }
            if (col0 == 0) a[i][0] = 0;
        }
    }
};

/*
APPROACH:
=> We will use the first row and the first column as the storage for makring zeroes
=> Iterate over the matrix and then wherever we encounter a zero mark that starting row and column as zero
*/

/*
Time Complexity: O(N * M)
Space Complexity: O(1)
*/
