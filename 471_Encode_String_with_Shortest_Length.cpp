/*
Problem link: https://leetcode.com/problems/encode-string-with-shortest-length/

Given a non-empty string, encode the string such that its encoded length is the shortest.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.

Note:

k will be a positive integer.
If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them.


Example 1:

Input: s = "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
Example 2:

Input: s = "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
Example 3:

Input: s = "aaaaaaaaaa"
Output: "10[a]"
Explanation: "a9[a]" or "9[a]a" are also valid solutions, both of them have the same length = 5, which is the same as "10[a]".
Example 4:

Input: s = "aabcaabcd"
Output: "2[aabc]d"
Explanation: "aabc" occurs twice, so one answer can be "2[aabc]d".
Example 5:

Input: s = "abbbabbbcabbbabbbc"
Output: "2[2[abbb]c]"
Explanation: "abbbabbbc" occurs twice, but "abbbabbbc" can also be encoded to "2[abbb]c", so one answer can be "2[2[abbb]c]".

*/

// solved by Milon

class Solution {
public:

    string encode(string s) {
        if (s.length() == 0) return "";
        if (mem.find(s) != mem.end()) return mem[s];
        string &ret = mem[s];
        ret = s;
        for(int i = 0; i < s.length(); i++) {
            string str = s.substr(0, i+1);
            int times = getRepeatedTimes(s, str);
            for(int t = 1; t <= times; t++) {
                string subs = s.substr(i+1);
                if (t == 1) {
                    string newStr = str + encode(subs);
                    if (newStr.length() < ret.length())
                       ret = newStr;
                } else {
                    string restStr = s.substr((i+1)*t);
                    string newStr = to_string(t) + "[" + encode(str) + "]" + encode(restStr);
                    if (newStr.length() < ret.length())
                       ret = newStr;
                }
            }
        }
        return ret;
    }
private:
    unordered_map<string, string> mem;

    int getRepeatedTimes(const string &s, const string &t) {
        int len = s.length();
        int j = 0;
        int tLen = t.length();
        int times = 0;
        for(int i = 0; i < len; i++) {
            if (s[i] == t[j]) {
                j++;
                if (j == tLen) {
                    times++;
                    j = 0;
                }
            } else
                break;
        }
        return times;
    }

};




