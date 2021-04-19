/*
Link:  https://leetcode.com/discuss/interview-question/647724/Google-or-Phone-or-Minimum-steps-to-destination, https://leetcode.com/problems/the-maze-ii

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return the shortest distance for the ball to stop at the destination. If the ball cannot stop at destination, return -1.

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {
public:

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    int shortestDistance(vector<vector<int>> maze, vector<int> start, vector<int> des) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> cost;
        cost.resize(n, vector<int> (m, INT_MAX));
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        cost[start[0]][start[1]] = 0;
        while (!q.empty()) {
            pair<int, int> top = q.front(); q.pop();
            int x = top.first;
            int y = top.second;
            int c = cost[x][y];
            for (int i = 0; i < 4; i++) {
                int ax = x + dr[i];
                int ay = y + dc[i];
                while (ax >= 0 && ax < n && ay >= 0 && ay < m && maze[ax][ay] == 0) {
                    ax += dr[i];
                    ay += dc[i];
                }
                ax -= dr[i];
                ay -= dc[i];
                int curCost = c + abs(x - ax) + abs(y - ay);
                if (curCost < cost[ax][ay]) {
                    cost[ax][ay] = curCost;
                    q.push({ax, ay});
                }
            }
        }
        if (cost[des[0]][des[1]] == INT_MAX) return -1;
        return cost[des[0]][des[1]];
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.shortestDistance({{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}}, {0,4}, {4,4}) << endl;
    return 0;
}
