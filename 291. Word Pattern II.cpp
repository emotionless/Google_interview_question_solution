/*
Link: https://leetcode.com/problems/word-pattern-ii/

Given a pattern and a string s, return true if s matches the pattern.

A string s matches a pattern if there is some bijective mapping of single characters to strings such that if each character in pattern is replaced by the string it maps to, then the resulting string is s. A bijective mapping means that no two characters map to the same string, and no character maps to two different strings.



Example 1:

Input: pattern = "abab", s = "redblueredblue"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "red"
'b' -> "blue"
Example 2:

Input: pattern = "aaaa", s = "asdasdasdasd"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "asd"
Example 3:

Input: pattern = "abab", s = "asdasdasdasd"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "a"
'b' -> "sdasd"
Note that 'a' and 'b' cannot both map to "asd" since the mapping is a bijection.
Example 4:

Input: pattern = "aabb", s = "xyzabcxzyabc"
Output: false


Constraints:

1 <= pattern.length, s.length <= 20
pattern and s consist of only lower-case English letters.
*/

// Milon

class Solution {
public:

    bool solve(int ind1, int ind2, const string pattern, const string s, unordered_map<char, string> hash, unordered_set<string> visited) {
        if (ind1 == pattern.length() || ind2 == s.length()) {
            return ind1 == pattern.length() && ind2 == s.length();
        }
        if (ind1 >= pattern.length() || ind2 >= s.length()) {
            return false;
        }
        int &ret = dp[ind1][ind2];
        //if (ret != -1) return ret;
        ret = 0;
        char ch = pattern[ind1];
        if (hash.find(ch) == hash.end()) {
            string str = "";
            for (int i = ind2; i < s.length(); i++) {
                str += s[i];
                if (visited.find(str) == visited.end()) {
                    visited.insert(str);
                    hash[ch] = str;
                    ret += solve(ind1 + 1, i + 1, pattern, s, hash, visited);
                    if (ret > 0) return ret;
                    hash.erase(ch);
                    visited.erase(str);
                }
            }
        } else {
            int sz = hash[ch].size();
            string str = s.substr(ind2, sz);
            if (str == hash[ch]) {
                ret += solve(ind1 + 1, ind2 + sz, pattern, s, hash, visited);
            }
        }
        auto p = hash[ch];
        // cout << ind1 << " " << ind2 << " " << p << " " << ret << endl;
        return ret;
    }



    bool wordPatternMatch(string pattern, string s) {
        if (pattern.size() == 1) return true;
        dp.resize(pattern.size(), vector<int>(s.length(), -1));
        unordered_map<char, string> hash;
        unordered_set<string> visited;
        return solve(0, 0, pattern, s, hash, visited);
    }
private:
    vector<vector<int>> dp;
};
