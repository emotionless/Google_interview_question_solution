/*
Link: https://leetcode.com/discuss/interview-question/915485/Google-or-Onsite-or-Highest-Peak

Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



Example 1:

Input:
[[0,0,0],
 [0,1,0],
 [0,0,0]]

Output:
[[0,0,0],
 [0,1,0],
 [0,0,0]]
Example 2:

Input:
[[0,0,0],
 [0,1,0],
 [1,1,1]]

Output:
[[0,0,0],
 [0,1,0],
 [1,2,1]]


Note:

The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>


using namespace std;

class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    const int INF = 10000000;

    void BFS(vector<vector<int>> &matrix, vector<vector<int>> &cost) {
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int, int>>q;
        cost.clear();
        cost.resize(n, vector<int> (m, INF));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i, j});
                    cost[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto frnt = q.front();
            q.pop();
            int x = frnt.first;
            int y = frnt.second;
            int c = cost[x][y];
            for (int i = 0; i < 4; i++) {
                int ax = x + dr[i];
                int ay = y + dc[i];
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || matrix[ax][ay] == 0)
                    continue;
                if ((c + 1) < cost[ax][ay]) {
                    cost[ax][ay] = c + 1;
                    q.push({ax, ay});
                }
            }
        }
        return;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>> matrix) {
        vector<vector<int>> cost;
        BFS(matrix, cost);
        return cost;
    }
};

int main() {
    Solution sol = Solution();
    auto ans = sol.updateMatrix({{0,0,0}, {0,1,0}, {0,0,0}});
    for (auto u : ans) {
        for (auto v : u) {
            cout << v << " ";
        }
        cout << endl;
    }


    return 0;
}
