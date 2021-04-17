/*
Link: https://leetcode.com/discuss/interview-question/125301/Find-longest-consecutive-path-in-a-matrix

Given a 2d matrix, each element in this matrix is unique, i.e. in a matrix of m*n, it contains integers from 1,2,3,..m*n.
Find the longest consecutive path in it. You could go in the four directions: right, left, up and down, no other directions allowed.

e.g.

in this matrix:

int[][] grid = new int[][]{
				{1,  2, 13,  5},
				{11, 10,  9,  6},
				{3,  4,  8,  7},
				{12, 14, 15, 16},
		};
The result should be this list: 5, 6, 7, 8, 9, 10, 11

Write your code in any language, and also analyze your time-complexity.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int solve(int i, int j, const vector<vector<int>> &matrix, vector<vector<bool>> &vis, vector<vector<int>> &cost) {
        int ret = 1;
        if (vis[i][j]) return cost[i][j];
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int ai = i + dr[k];
            int aj = j + dc[k];
            if (ai < 0 || ai >= matrix.size() || aj < 0 || aj >= matrix[0].size() || matrix[ai][aj] != (matrix[i][j] + 1)) continue;
            ret += solve(ai, aj, matrix, vis, cost);
        }
        return cost[i][j] = ret;
    }

    int longestConsecutivePath(vector<vector<int>> matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> cost(n, vector<int>(m, 0));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    ans = max(ans, solve(i, j, matrix, vis, cost));
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution sl = Solution();
    vector<vector<int>> vec{{1,  2, 13,  5},
				{11, 10,  9,  6},
				{3,  4,  8,  7},
				{12, 14, 15, 16}};
    cout << sl.longestConsecutivePath(vec) << endl;

    return 0;
}
