/*
Link: https://leetcode.com/problems/palindrome-permutation-ii/
Solved by: emotionless

Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

Example 1:
Input: "aabb"
Output: ["abba", "baab"]


Example 2:
Input: "abc"
Output: []


*/

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> counter;
        for (auto ch : s) {
            counter[ch]++;
        }
        char take = ' ';
        for (auto &cur : counter) {
            if (cur.second&1) {
                if (take != ' ') {
                    return {};
                }
                take = cur.first;
                cur.second--;
            }
        }
        string str = "";
        for (auto cur : counter) {
            int cnt = cur.second / 2;
            for(int j = 0; j < cnt; j++) {
                str += cur.first;
            }
        }
        cout << str << endl;
        int l = str.length();
        vector<string> ans;
        sort(str.begin(), str.end());
        do {
            string now = "";
            for (int i = 0; i < l; i++) {
                now += str[i];
            }
            string cp = now;
            reverse(cp.begin(), cp.end());
            if (take != ' ') now += take;
            now = now + cp;
            ans.push_back(now);
        } while(next_permutation(str.begin(), str.end()));

        return ans;
    }
};
