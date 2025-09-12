class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> counter(numCourses, 0);
        vector<vector<int>> to(numCourses, vector<int>());
        for (auto &pre : prerequisites) {
            counter[pre[0]]++;
            to[pre[1]].push_back(pre[0]);
        }
        queue<int> candidates;
        for (int i = 0; i < numCourses; i++) {
            if (counter[i] == 0) {
                candidates.push(i);
            }
        }
        while (!candidates.empty()) {
            int cur = candidates.front();
            candidates.pop();
            for (int &v : to[cur]) {
                counter[v]--;
                if (counter[v] == 0) {
                    candidates.push(v);
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (counter[i] > 0) return false;
        }
        return true;
    }
};