/*


In an infinite chess board with coordinates from -infinity to +infinity, you have a knight at square [0, 0].

A knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.



Return the minimum number of steps needed to move the knight to the square [x, y].  It is guaranteed the answer exists.



Example 1:

Input: x = 2, y = 1
Output: 1
Explanation: [0, 0] → [2, 1]
Example 2:

Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]


Constraints:

|x| + |y| <= 300

*/

class Solution
{
public:

    int distance(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int minKnightMoves(int x, int y)
    {
        int cost[601][601];
        x += 300;
        y += 300;
        memset(cost, 0, sizeof cost);
        queue<pair<int, int>> q;
        q.push(make_pair(300, 300));
        cost[300][300] = 1;
        while(!q.empty())
        {
            pair<int, int> cn = q.front();
            q.pop();
            int cx = cn.first;
            int cy = cn.second;

            if (cx == x && cy == y)
            {
                return cost[cx][cy] - 1;
            }
            for (int i = 0; i < 8; i++)
            {
                int ax = cx + dr[i];
                int ay = cy + dc[i];
                pair<int, int> p = make_pair(ax, ay);
                if (ax < 0 || ax > 600 || ay < 0 || ay > 600)
                    continue;
                if (cost[ax][ay] == 0)
                {
                    cost[ax][ay] = cost[cx][cy] + 1;
                    q.push(p);
                }
            }
        }
        return -1;
    }
};
