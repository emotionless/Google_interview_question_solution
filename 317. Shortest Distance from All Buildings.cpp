/*
Problem link: https://leetcode.com/problems/shortest-distance-from-all-buildings/

You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total
             travel distance of 3+3+1=7 is minimal. So return 7.

*/

// solved by Milon

class Solution {
public:

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};


    void shortestDistance(const vector<vector<int>> &grid, int x, int y) {
        queue<pair<pair<int, int>, int>> q;
        bool vis[n][m];
        memset(vis, false, sizeof vis);

        q.push(make_pair(make_pair(x, y), 0));

        vis[x][y] = true;
        while(!q.empty()) {
            pair<pair<int, int>, int> top = q.front();
            q.pop();
            int cx = top.first.first;
            int cy = top.first.second;
            int cc = top.second;
            cost[cx][cy] += cc;
            cnt[cx][cy]++;


            for(int i = 0; i < 4; i++) {
                int ax = cx + dr[i];
                int ay = cy + dc[i];
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || vis[ax][ay] || grid[ax][ay] != 0) continue;
                vis[ax][ay] = true;
                q.push(make_pair(make_pair(ax, ay), cc + 1));
            }
        }
        return;
    }

    int shortestDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        cnt.resize(n, vector<int>(m, 0));
        cost.resize(n, vector<int>(m, 0));
        int res = INT_MAX;
        int tot = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    tot++;
                    shortestDistance(grid, i, j);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                   if (cnt[i][j] == tot) {
                       res = min(res, cost[i][j]);
                   }
                }
            }
        }
        if (res == INT_MAX) return -1;
        return res;
    }
private:
    vector<vector<int>> cnt, cost;
    int n, m;
};
