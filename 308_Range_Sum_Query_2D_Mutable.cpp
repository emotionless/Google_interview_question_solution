/*
Solved by: emotionless
Problem link: https://leetcode.com/problems/range-sum-query-2d-mutable/

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10

*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) return;
        m = matrix[0].size();

        sum.resize(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum[i][j] = matrix[i][j] + (j?sum[i][j-1] : 0);
            }
        }
    }

    void update(int row, int col, int val) {
        int dif = (col == 0? val - sum[row][col] : val - sum[row][col] + sum[row][col-1]);
        for(int i = col; i < m; i++) {
            sum[row][i] += dif;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1; i <= row2; i++) {
            ans += sum[i][col2] - (col1?sum[i][col1-1] : 0);
        }
        return ans;
    }
private:
    int n, m;
    vector<vector<int>> sum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
