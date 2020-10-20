
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>


using namespace std;

class MinDistance {
public:

    int getMinDist(int n, const vector<vector<int>> edges) {
        adj.clear();
        adj.resize(n + 1);
        mx = 0, node = -1;
        for(auto v : edges) {
            adj[ v[0] ].push_back(v[1]);
            adj[ v[1] ].push_back(v[0]);
        }
        dfs(1, 0, -1);
        int pre = node;
        dfs(pre, 0, -1);
        return mx / 2 + mx%2;
    }

private:
    vector<vector<int>> adj;
    int mx = 0, node = -1;

    void dfs(int u, int c, int p) {
        if (c > mx) {
            mx = c;
            node = u;
        }
        for(auto v : adj[u]) {
            if (v != p)
                dfs(v, c + 1, u);
        }

        return;
    }
};

vector<int> createNode(int u, int v) {
    vector<int> tmp;
    tmp.push_back(u);
    tmp.push_back(v);

    return tmp;
}

int main()
{
    MinDistance md;

    cout << md.getMinDist(6, {{1, 4}, {2, 3}, {3, 4}, {4, 5}, {5, 6}}) << endl;
    cout << md.getMinDist(10, {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}}) << endl;
    cout << md.getMinDist(10, {{7, 8}, {7, 9}, {4, 5}, {1, 3}, {3, 4}, {6, 7}, {4, 6}, {2, 3}, {9, 10}}) << endl;

    return 0;
}

/*

Time complexity:
O(n)

Space complexity:
O(n)

*/
