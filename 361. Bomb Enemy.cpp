/*
Link: https://leetcode.com/problems/bomb-enemy/

Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.



Example 1:


Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3
Example 2:


Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 'W', 'E', or '0'.
*/


// solved by Milon

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();
        if (m == 0)
            return 0;
        vector<vector<int>> left, right, up, down;
        left.resize(n, vector<int>(m, 0));
        right.resize(n, vector<int>(m, 0));
        up.resize(n, vector<int>(m, 0));
        down.resize(n, vector<int>(m, 0));
        // left to right
        for (int i = 0; i < n; i++) {
            int consecutive = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'E')
                    consecutive++;
                else if (grid[i][j] == 'W')
                    consecutive = 0;
                left[i][j] = consecutive;
            }
        }
        // right to left
        for (int i = 0; i < n; i++) {
            int consecutive = 0;
            for (int j = m-1; j >= 0; j--) {
                if (grid[i][j] == 'E')
                    consecutive++;
                else if (grid[i][j] == 'W')
                    consecutive = 0;
                right[i][j] = consecutive;
            }
        }

        // up to down
        for (int j = 0; j < m; j++) {
            int consecutive = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 'E')
                    consecutive++;
                else if (grid[i][j] == 'W')
                    consecutive = 0;
                up[i][j] = consecutive;
            }
        }
        // down to up
        for (int j = 0; j < m; j++) {
            int consecutive = 0;
            for (int i = n-1; i >= 0; i--) {
                if (grid[i][j] == 'E')
                    consecutive++;
                else if (grid[i][j] == 'W')
                    consecutive = 0;
                down[i][j] = consecutive;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') {
                    ans = max(ans, left[i][j] + right[i][j] + up[i][j] + down[i][j]);
                }
            }
        }
        return ans;
    }
};
