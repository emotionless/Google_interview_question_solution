/*
Problem link: https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/

Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
Example:
Input:
[[0,1,1,0],
 [0,1,1,0],
 [0,0,0,1]]
Output: 3
Hint: The number of elements in the given matrix will not exceed 10,000.

*/

// Solved by Milon

class Solution {
public:
    int longestLine(const vector<vector<int>>& M) {
        const int n = M.size();
        if (n == 0) return 0;
        const int m = M[0].size();
        if (m == 0) return 0;

        vector<vector<int>> diagSum, antiDiagSum;
        vector<int> colSum;
        colSum.resize(m, 0);
        diagSum.resize(n, vector<int>(m, 0));
        antiDiagSum.resize(n, vector<int>(m, 0));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int rowSum = 0;
            for(int j = 0; j < m; j++) {
                if (M[i][j] == 0) {
                    rowSum = 0;
                    colSum[j] = 0;
                    diagSum[i][j] = 0;
                    antiDiagSum[i][j] = 0;
                } else {
                    rowSum += M[i][j];
                    ans = max(ans, rowSum);
                    colSum[j] += M[i][j];
                    ans = max(ans, colSum[j]);
                    diagSum[i][j] += M[i][j] + (((i-1) >= 0 && (j-1) >= 0)? diagSum[i-1][j-1] : 0);
                    ans = max(ans, diagSum[i][j]);
                    antiDiagSum[i][j] = M[i][j] + (((i-1) >= 0 && (j+1) < m)? antiDiagSum[i-1][j+1] : 0);
                    ans = max(ans, antiDiagSum[i][j]);
                }
            }
        }
        return ans;
    }
};
