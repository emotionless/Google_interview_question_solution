/*
Link: https://csacademy.com/contest/archive/task/move-the-bishop/statement/

On a chessboard of size 8 \times 88×8 there is a bishop on cell (R_1, C_1)(R
1
​
 ,C
1
​
 ). You want to move the bishop to cell (R_2, C_2)(R
2
​
 ,C
2
​
 ), using the minimum number of moves.

A bishop is a chess piece which has no restrictions in distance for each move, but is limited to diagonal movement. Basically, in a move you can take the bishop to any cell that shares a diagonal with the initial cell.

Standard input
The first line contains 44 integers R_1, C_1, R_2, C_2R
1
​
 ,C
1
​
 ,R
2
​
 ,C
2
​
 .

Standard output
If there is no solution output -1−1.

Otherwise, print the minimum number of moves on the first line.

Constraints and notes
1 \leq R_1, C_1, R_2, C_2 \leq 81≤R
1
​
 ,C
1
​
 ,R
2
​
 ,C
2
​
 ≤8
Input	Output	Explanation
3 2 6 5
1
The start position is labeled with S

The finish one with F

The path from S to F with #

........


3 2 3 8
2
..#...#.


3 2 4 4
-1
There's no path from the start position the finish one.


*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int dr[4] = {-1, -1, 1, 1};
int dc[4] = {-1, 1, 1, -1};

const int n = 8;
const int INF = 100000000;


int bfs(int stx, int sty, int edx, int edy) {
    vector<vector<int>> cost(n, vector<int>(n, INF));
    queue<pair<int, int>> q;
    q.push(make_pair(stx, sty));
    cost[stx][sty] = 0;

    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        int x = top.first;
        int y = top.second;
        if (x == edx && y == edy) {
            return cost[x][y];
        }
        for (int i = 0; i < 4; i++) {
            int ax = x, ay = y;
            while (ax >= 0 && ax < n && ay >= 0 && ay < n) {
                ax = ax + dr[i];
                ay = ay + dc[i];
                if (ax < 0 || ax >= n || ay < 0 || ay >= n || cost[ax][ay] < (cost[x][y] + 1)) continue;
                cost[ax][ay] = cost[x][y] + 1;
                q.push(make_pair(ax, ay));
            }
        }
    }
    return -1;
}

int main() {
    int stx, sty, edx, edy;
    cin >> stx >> sty >> edx >> edy;
    cout << bfs(stx - 1, sty - 1, edx - 1, edy - 1) << endl;

    return 0;
}
