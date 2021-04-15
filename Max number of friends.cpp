/*
Link: https://leetcode.com/discuss/interview-question/907250/Google-or-Phone-or-Max-number-of-friends

You want to invite as many friends to your party as possible. You're given list of tuples where each tuple consists of two friend ids and they don't like each other. Your task is to invite as many friends as possible. Output of the task - max number of friends you can invite which don't have conflicts with each other.

Input: [(1, 2), (2, 3), (3, 4)]
Ouput: 2 (it's either (1, 3) or (2, 4) or (1, 4)

*/

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <set>

using namespace std;

class Friends {
public:
    int getMaxFriends(vector<pair<int, int>> arr) {
        int n = arr.size();
        adjn.clear();
        int mx = 0;
        for (auto v : arr) {
            mx = max(mx, v.first);
            mx = max(mx, v.second);
        }
        adjn.resize(mx + 1);
        for (auto v : arr) {
            adjn[v.first].push_back(v.second);
            adjn[v.second].push_back(v.first);
        }
        int ans = 0;
        for (int i = 1; i <= mx; i++) {
            vis.clear();
            cnter.clear();
            solve(i);
            ans = max(ans, cnter[0]);
        }
        return ans;
    }

private:
    vector<vector<int>> adjn;
    unordered_map<int, int> vis, cnter;

    void solve(int u) {
        if (vis.find(u) != vis.end()) {
            return;
        }
        vis[u] = -1;
        set<int> st;
        for (auto v : adjn[u]) {
            if (vis.find(v) != vis.end()) {
                st.insert(vis[v]);
            }
        }
        int id = 0;
        while(st.size()) {
            auto top = *st.begin();
            if (top != id) {
                break;
            }
            id++;
            st.erase(st.begin());
        }
        vis[u] = id;
        cnter[id]++;
        for (auto v : adjn[u]) {
            if (vis.find(v) == vis.end()) {
                solve(v);
            }
        }
        return;
    }
};

int main() {
    Friends frnds = Friends();
    cout << frnds.getMaxFriends({{1, 2}, {2, 3}, {3, 4}}) << endl;
    cout << frnds.getMaxFriends({{1, 2}, {2, 3}, {3, 4}, {1, 4}, {4, 5}, {1, 5}, {5, 6}, {1, 6}}) << endl;

    return 0;
}

/*
Time: O(N^3)
Space: O(N)
*/
