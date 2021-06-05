/*
Link:  https://leetcode.com/problems/the-maze/

There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).



Example 1:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
Example 2:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false


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

class Solution {
public:

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool valid(int ax, int ay, int n, int m) {
        return ax >= 0 && ax < n && ay >= 0 && ay < m;
    }

    bool bfs(const vector<int> &source, const vector<int> &destination, const vector<vector<int>> &maze) {
        queue<pair<int, int>> q;
        q.push({source[0], source[1]});
        vis[source[0]][source[1]] = true;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if (x == destination[0] && y == destination[1]) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int ax = x;
                int ay = y;
                while (valid(ax + dr[i], ay + dc[i], n, m) && maze[ax+dr[i]][ay+dc[i]] == 0) {
                    ax += dr[i];
                    ay += dc[i];
                }
                if (vis[ax][ay] == true)
                    continue;
                vis[ax][ay] = true;
                q.push({ax, ay});
            }
        }
        return false;
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        n = maze.size();
        m = maze[0].size();
        vis.resize(n, vector<bool>(m, false));
        return bfs(start, destination, maze);
    }
private:
    int n, m;
    vector<vector<bool>> vis;
};

/*

000
000
000

0 2
2 0

*/
