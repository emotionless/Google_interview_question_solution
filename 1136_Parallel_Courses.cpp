/*
Problem link: https://leetcode.com/problems/parallel-courses/

There are N courses, labelled from 1 to N.

We are given relations[i] = [X, Y], representing a prerequisite relationship between course X and course Y: course X has to be studied before course Y.

In one semester you can study any number of courses as long as you have studied all the prerequisites for the course you are studying.

Return the minimum number of semesters needed to study all courses.  If there is no way to study all the courses, return -1.

Input: N = 3, relations = [[1,3],[2,3]]
Output: 2
Explanation:
In the first semester, courses 1 and 2 are studied. In the second semester, course 3 is studied.

*/

// solved by: Milon

class Solution {
public:

    const int mx = 1000000;
    vector<vector<int>> adj;
    vector<int> cost;
    int DFS(int ind, const int N) {
        if (ind > N) return 0;
        int &ret = cost[ind];
        if (ret != -1) return ret;
        ret = 1;
        for(auto v : adj[ind]) {
            ret = max(ret, 1 + DFS(v, N));
        }
        return ret;
    }

    int minimumSemesters(int N, vector<vector<int>>& relations) {
        adj.resize(N+1);
        int deg[N+1];
        memset(deg, 0, sizeof deg);
        for(auto v : relations) {
            adj[v[0]].push_back(v[1]);
            deg[v[1]]++;
        }
        cost.resize(N+1, -1);
        queue<int> q;
        for(int i = 1; i <= N; i++) {
            if (deg[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            for(auto v : adj[top]) {
                deg[v]--;
                if (deg[v] == 0) q.push(v);
            }
        }
        for(int i = 1; i <= N; i++) {
            if (deg[i]) return -1;
        }

        for(int i = 1; i <= N; i++) {
            if (cost[i] == -1) {
                DFS(i, N);
            }
        }
        int ans = 0;
        for(int i = 1; i <= N; i++) {
            ans = max(ans, cost[i]);
        }
        return ans;
    }
};
