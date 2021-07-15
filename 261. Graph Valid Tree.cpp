/*
Link: https://leetcode.com/problems/graph-valid-tree/

You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.



Example 1:


Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false


Constraints:

1 <= 2000 <= n
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.
*/


// solved by Milon

class Solution {
public:

    void dfs(int u, const vector<vector<int>> &adj, vector<bool> &vis) {
        if (vis[u])
            return;
        vis[u] = true;
        for (auto v : adj[u]) {
            dfs(v, adj, vis);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if ((n-1) != edges.size())
            return false;
        vector<vector<int>> adj(n);
        for (auto ele : edges) {
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        vector<bool> vis(n, false);
        dfs(0, adj, vis);
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                return false;
            }
        }
        return true;
    }
};
