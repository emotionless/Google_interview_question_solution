/*
Link: https://leetcode.com/discuss/interview-question/1361977/Google-or-SDE-2-or-Onsite-or-Shortest-Path-with-twist

A country has multiple cities which are represented as vertices of a graph and cities are interconnected with each other through roads. These roads are represented as undirected edges between the vertices with unit weight (same weight for all roads). Now calculate the shortest path between 'A' to 'B' such that you are travelling in a car with a capacity of 'c' and there are only few cities which have fuel stations where you can fill the car to complete capacity (when you visit that vertex). When you travel from one city to another you conume a unit of fuel and at the source city you start with full capacity of fuel.

Sample Input:
Roads: [[1,2],[2,3],[3,4],[4,5],[4,6],[6,7]]
A: 1, B: 7, capacity 'c': 4
fuel stations: [5]

Graphical notation of input graph
1
|
2
|
3
|
4 - 5
|
6
|
7

sample output: 7 (as shortest path is 1-2-3-4-5-4-6-7)

*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int shortestPathWithTwist(int n, vector< pair<int, int> > edges, int st, int ed, int cap, vector<int> stations) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    vector<int> capacity(n, 0);
    capacity[st] = cap;
    for (auto v : stations) {
        capacity[v] = cap;
    }
    vector<int> fuel(n, 0);
    fuel[st] = cap;
    queue<pair<int, int>> q;
    q.push({st, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.first == ed) {
            return cur.second;
        }
        int u = cur.first;
        for (auto v : adj[u]) {
            if (max(capacity[v], fuel[u] - 1) > fuel[v]) {
                fuel[v] = max(capacity[v], fuel[u] - 1);
                q.push({v, cur.second + 1});
            }
        }
    }
    return -1;  // unreachable
}

int main() {
    const int n = 8;
    vector< pair<int, int> > edges;
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});
    edges.push_back({4, 5});
    edges.push_back({4, 6});
    edges.push_back({6, 7});

    cout << shortestPathWithTwist(n, edges, 1, 7, 4, {5}) << endl;

    return 0;
}
