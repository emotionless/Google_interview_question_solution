/*
Problem link: https://leetcode.com/problems/path-with-maximum-minimum-value/

Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).



Example:

Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4

Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2

Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3

*/

// solved by Milon

class Solution {
public:

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    struct node {
        int x, y, c;
        node(int _x, int _y, int _c) {
            x = _x;
            y = _y;
            c = _c;
        }
        bool operator<(const node &A) const {
            return c < A.c;
        }
    };

    int maximumMinimumPath(const vector<vector<int>>& A) {
        priority_queue<node> pq;
        pq.push(node(0, 0, A[0][0]));
        int n = A.size();
        int m = A[0].size();
        vis.resize(n, vector<bool>(m, false));
        vis[0][0] = true;
        int ans = A[0][0];
        while(!pq.empty()) {
            node cur = pq.top();
            pq.pop();
            int x = cur.x;
            int y = cur.y;
            int c = cur.c;
            // cout << x << " " << y << " " << c << endl;
            ans = min(ans, c);
            pair<int, int> p = make_pair(x, y);
            if (x == (n-1) && y == (m-1)) return ans;
            for(int i = 0; i < 4; i++) {
                int ax = dr[i] + x;
                int ay = dc[i] + y;
                if (ax < 0 || ax >= n || ay < 0 || ay >= m || vis[ax][ay]) continue;
                vis[ax][ay] = true;
                pq.push(node(ax, ay, A[ax][ay]));
            }
        }
        return -1;
    }

private:
    vector<vector<bool>> vis;
};
