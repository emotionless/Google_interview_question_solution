/*
Link: https://leetcode.com/problems/the-maze-ii/

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return the shortest distance for the ball to stop at the destination. If the ball cannot stop at destination, return -1.

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).



Example 1:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: 12
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
Example 2:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: -1
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: -1


Constraints:

m == maze.length
n == maze[i].length
1 <= m, n <= 100
maze[i][j] is 0 or 1.
start.length == 2
destination.length == 2
0 <= startrow, destinationrow <= m
0 <= startcol, destinationcol <= n
Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
The maze contains at least 2 empty spaces.
*/

// solved by Milon

class Solution {
public:

    struct node {
        int x, y, c;
        node(int newX, int newY, int newC) {
            x = newX;
            y = newY;
            c = newC;
        }
    };

    struct comparator {
        bool operator()(const node &a, const node &b) {
            return -a.c < -b.c;
        }
    };

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    const int INF = 100000000;

    int dijkstra(const vector<int> &start, const vector<int> &des, const vector<vector<int>> &maze) {
        int n = maze.size();
        if (n == 0)
            return -1;
        int m = maze[0].size();
        if (m == 0)
            return -1;
        vector<vector<int>> cost(n, vector<int>(m, INF));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<node, vector<node>, comparator> pq;
        pq.push(node(start[0], start[1], 0));
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if (top.x == des[0] && top.y == des[1]) {
                return cost[top.x][top.y];
            }
            if (vis[top.x][top.y])
                continue;
            vis[top.x][top.y] = true;
            cost[top.x][top.y] = top.c;
            for (int i = 0; i < 4; i++) {
                int ax = top.x;
                int ay = top.y;
                int c = top.c;
                int cnt = 0;
                while ((ax + dr[i]) >= 0 && (ax + dr[i]) < n && (ay + dc[i]) >= 0 && (ay + dc[i]) < m && maze[ax + dr[i]][ay + dc[i]] == 0) {
                    ax += dr[i];
                    ay += dc[i];
                    if (!vis[ax][ay])
                        cnt++;
                }
                if (vis[ax][ay])
                    continue;
                if (cost[ax][ay] <= (cnt + c))
                    continue;
                cost[ax][ay] = min(cost[ax][ay], cnt + c);
                pq.push(node(ax, ay, cost[ax][ay]));
            }
        }
        return -1;
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return dijkstra(start, destination, maze);
    }
};
