/*
Problem link: https://leetcode.com/problems/alien-dictionary/


There is a new alien language that uses the English alphabet. However, the order among letters are unknown to you.

You are given a list of strings words from the dictionary, where words are sorted lexicographically by the rules of this new language.

Derive the order of letters in this language, and return it. If the given input is invalid, return "". If there are multiple valid solutions, return any of them.



Example 1:

Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
Example 2:

Input: words = ["z","x"]
Output: "zx"
Example 3:

Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".


Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.

*/

// solved by Milon

class Solution {
public:

    pair<char, char> getRelation(const string &word1, const string &word2) {
        int l = min(word1.length(), word2.length());
        for(int i = 0; i < l; i++) {
            if (word1[i] != word2[i]) {
                return make_pair(word1[i], word2[i]);
            }
        }
        return make_pair(' ', word1.size() == l? word2[l] : word1[l]);
    }
    int counter[150] = {0};
    vector<char> adj[150];
    map<char, bool> vis;

    string alienOrder(const vector<string>& words) {
        int sz = words.size();
        for(auto word : words) {
            for(auto ch : word) {
               vis[ch] = true;
            }
        }
        for(int i = 1; i < sz; i++) {
            pair<char, char> rel = getRelation(words[i-1], words[i]);
            if (rel.first == ' ' && words[i-1].length() > words[i].length()) return "";
            adj[rel.first].push_back(rel.second);
            counter[rel.second]++;
        }
        queue<char> q;
        q.push(' ');
        for(char i = 'a'; i <= 'z'; i++) {
                if (counter[i] == 0)
                    q.push(i);
        }
        string ans;
        ans.resize(26);
        int l = 0;
        while(q.size() > 0) {
            char cur = q.front();
            q.pop();
            if (vis.find(cur) != vis.end())
                ans[l++] = cur;
            vis.erase(cur);
            for(auto ch : adj[cur]) {
                counter[ch]--;
                if (counter[ch] == 0) q.push(ch);
            }
        }
        ans.resize(l);
        if (vis.size()) return "";
        return ans;
    }

};
