/*
Problem link: https://leetcode.com/problems/the-most-similar-path-in-a-graph/


We have n cities and m bi-directional roads where roads[i] = [ai, bi] connects city ai with city bi. Each city has a name consisting of exactly 3 upper-case English letters given in the string array names. Starting at any city x, you can reach any city y where y != x (i.e. the cities and the roads are forming an undirected connected graph).

You will be given a string array targetPath. You should find a path in the graph of the same length and with the minimum edit distance to targetPath.

You need to return the order of the nodes in the path with the minimum edit distance, The path should be of the same length of targetPath and should be valid (i.e. there should be a direct road between ans[i] and ans[i + 1]). If there are multiple answers return any one of them.

The edit distance is defined as follows:
// Number of mismatch positions


Follow-up: If each node can be visited only once in the path, What should you change in your solution?


*/

// solved by Milon

class Solution {
public:

    int solve(int ind, int id, const vector<string>& names, const vector<string>& targetPath) {
        if (id == targetPath.size()) {
            return 0;
        }
        int &ret = dp[ind][id];
        if (ret != -1) return ret;
        ret = INF;
        for(auto v : adj[ind]) {
            int a = solve(v, id + 1, names, targetPath);
            if (a < ret) {
                ret = a;
                path[ind][id] = v;
            }
        }
        ret += (names[ind] != targetPath[id]? 1: 0);

        return ret;
    }

    void makePath(int ind, int id, const int m, vector<int> &fullPath) {
        if (ind == -1 || id == m) return;
        fullPath.push_back(ind);
        int nxt = path[ind][id];
        makePath(nxt, id+1, m, fullPath);

        return;
    }

    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        int m = targetPath.size();
        dp.resize(n, vector<int>(m+1, -1));
        path.resize(n, vector<int>(m+1, -1));
        adj.resize(n);

        for(auto v : roads) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int res = INF;
        int st = -1;
        for(int i = 0; i < n; i++) {
            int r = solve(i, 0, names, targetPath);
            if (r < res) {
                res = r;
                st = i;
            }
        }
        vector<int> ans;
        makePath(st, 0, m, ans);


        return ans;
    }

private:
    vector<vector<int>> dp, path;
    vector<vector<int>> adj;
    const int INF = 1000000;
};
