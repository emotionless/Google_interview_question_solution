/*
Link: https://leetcode.com/discuss/interview-question/657455/fb-london-phone-screen-rejection

There are N people. We have information about interests of each person. Your task is to find minimum number of groups that these people can be placed into so there are no any 2 persons who share the same interests in one particular group e.g. {"A":['lit', 'math'], "B":['math'], "C":['sci']} A and B cannot be in the same group but C can go either with A or B. Each person can have infinitely large number of interests. So answer for this example will be 2.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:

    void DFS(int u) {
        if (vis[u] == true) return;
        vis[u] = true;
        unordered_map<int, bool> taken;
        for (auto v : adj[u]) {
            if (vis[v]) {
                taken[col[v]] = true;
            }
        }
        int cur = -1;
        for (int i = 0; ; i++) {
            if (taken.find(i) == taken.end()) {
                cur = i;
                break;
            }
        }
        col[u] = cur;
        colorNum = max(colorNum, cur);
        for (auto v : adj[u]) {
            if (!vis[v]) {
                DFS(v);
            }
        }
        return;
    }

    bool isCommonInterest(vector<string> a, vector<string> b) {
        unordered_set<string> st;
        for (string str : a) {
            st.insert(str);
        }
        for (string str : b) {
            st.insert(str);
        }
        return st.size() != (a.size() + b.size());
    }

    int minGroup(vector<vector<string>> interests) {
        int n = interests.size();
        adj.clear();
        adj.resize(n);
        vis.clear();
        vis.resize(n);
        col.clear();
        col.resize(n);
        colorNum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isCommonInterest(interests[i], interests[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                DFS(i);
            }
        }
        return colorNum;
    }
private:
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int> col;
    int colorNum = 0;
};


int main() {
    Solution sl = Solution();
    cout << sl.minGroup({{"lit", "math"}, {"math"}, {"sci"}}) + 1 << endl;

    return 0;
}
