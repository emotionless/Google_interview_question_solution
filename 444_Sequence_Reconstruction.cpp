/*
Problem link:https://leetcode.com/problems/sequence-reconstruction/

Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs.
The org sequence is a permutation of the integers from 1 to n, with 1 <= n <= 104.
Reconstruction means building a shortest common supersequence of the sequences in seqs
(i.e., a shortest sequence so that all sequences in seqs are subsequences of it).
Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.



Example 1:

Input: org = [1,2,3], seqs = [[1,2],[1,3]]
Output: false
Explanation: [1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.
Example 2:

Input: org = [1,2,3], seqs = [[1,2]]
Output: false
Explanation: The reconstructed sequence can only be [1,2].
Example 3:

Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Output: true
Explanation: The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].
Example 4:

Input: org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
Output: true


Constraints:

1 <= n <= 10^4
org is a permutation of {1,2,...,n}.
1 <= segs[i].length <= 10^5
seqs[i][j] fits in a 32-bit signed integer.

*/


// Solved by Milon

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        vector<int> tmp;
        for(auto v : seqs) {
            for(auto u : v) {
                tmp.push_back(u);
            }
        }
        sort(tmp.begin(), tmp.end());
        map<int, int> M;
        int ind = 0;
        if (tmp.size() == 0) return false;
        M[tmp[0]] = ind++;
        for(int i = 1; i < tmp.size(); i++) {
            if (tmp[i] != tmp[i-1]) {
                M[ tmp[i] ] = ind++;
            }
        }
        for(auto &v : org) {
            if (M.find(v) == M.end()) return false;
            v = M[v];
        }
        for(auto &v : seqs) {
            for(auto &u : v) {
                u = M[u];
            }
        }

        vector<vector<int>> adjn;
        int n = org.size();
        if (n != ind) return false;
        adjn.resize(n+1);
        unordered_map<int, int> cnt;
        map<pair<int,int>, bool> vis;
        if (seqs.size() == 0 || org.size() == 0) {
            return seqs.size() == 0 && org.size() == 0;
        }
        // bool seen[10001] = {false};

        for(auto v : seqs) {
            int sz = v.size();
            for(int i = 1; i < sz; i++) {
                pair<int, int> p = make_pair(v[i-1], v[i]);
                if (vis.find(p) == vis.end()) {
                    adjn[v[i-1]].push_back(v[i]);
                    cnt[v[i]]++;
                    vis[p] = true;

                   // seen[v[i]] = true;
                }
            }
            // seen[v[0]] = true;
        }
        queue<int> q;
        unordered_map<int, bool> seen;
        for(auto v : seqs) {
            int sz = v.size();
            for(auto u : v) {
                if (cnt[u] == 0 && seen.find(u) == seen.end()) {
                    q.push(u);
                    seen[u] = true;
                }
            }
        }
        vector<int> ans;
        int tot = 0;
        while(!q.empty()) {
            if (q.size() > 1) return false;
            int cn = q.front();
            q.pop();
            ans.push_back(cn);
            seen[cn] = true;
            tot++;
            for(auto v : adjn[cn]) {
                cnt[v]--;
                if (cnt[v] == 0) q.push(v);
            }
        }

        if (tot != org.size()) return false;
        if (ans.size() != org.size()) return false;
        cout << "dsf" << endl;
        for(int i = 0; i < ans.size(); i++) {
            if (ans[i] != org[i]) return false;
        }
        // cout << "sfasdf"<<endl;
        for(int i = 1; i <= n; i++) {
            if (cnt[i]) return false;
            if (!seen[ org[i-1] ]) return false;
        }

        return true;
    }
};
