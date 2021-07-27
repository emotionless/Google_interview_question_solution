/*
Link: https://leetcode.com/problems/number-of-distinct-islands/

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Return the number of distinct islands.



Example 1:


Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
Output: 1
Example 2:


Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

// solved by Milon

class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    char getDirection(int d) {
        if (d == 0)
            return 'U';
        else if (d == 1)
            return 'R';
        else if (d == 2)
            return 'D';
        return 'L';
    }

    string dfs(int r, int c, vector<vector<int>> &grid) {
        string ret = "";
        grid[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int adjr = r + dr[i];
            int adjc = c + dc[i];
            if (adjr < 0 || adjr >= n || adjc < 0 || adjc >= m || grid[adjr][adjc] == 0) {
                ret += '#';
                continue;
            }
            ret += getDirection(i) + dfs(adjr, adjc, grid);
        }
        return ret;
    }

    int numDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        unordered_set<string> container;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    string hashed = dfs(i, j, grid);
                    container.insert(hashed);
                }
            }
        }
        return container.size();
    }
private:
    int n, m;
};
