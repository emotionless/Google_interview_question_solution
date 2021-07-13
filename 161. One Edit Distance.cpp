/*
Link: 161. One Edit Distance

Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.
 

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "a", t = ""
Output: true
Example 4:

Input: s = "", t = "A"
Output: true
 

Constraints:

0 <= s.length <= 104
0 <= t.length <= 104
s and t consist of lower-case letters, upper-case letters and/or digits.
*/

// solved by Milon
class Solution {
public:
    bool isOneEditDist(const string s, const string t) {
        if ((t.length() - s.length()) != 1) return false;
        int len = s.length();
        int j = 0;
        for (int i = 0; i < t.length() && j < len; i++) {
            if (t[i] != s[j]) {
                if (i != j) return false;
            } else {
                j++;
            }
        }
        return j == len;
    }
    bool isOneEditDistance(string s, string t) {
        if (isOneEditDist(s, t) || isOneEditDist(t, s)) return true;
        if (s.length() != t.length()) return false;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) cnt++;
        }
        return cnt == 1;
    }
};