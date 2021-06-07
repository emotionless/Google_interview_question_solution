/*
Link: https://leetcode.com/problems/shortest-way-to-form-string/

From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.



Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".
Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.
Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".


Constraints:

Both the source and target strings consist of only lowercase English letters from "a"-"z".
The lengths of source and target string are between 1 and 1000.

*/

class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0;
        int len = source.length();
        int ans = 1;
        for (auto ch : target) {
            bool ck = false;
            int times = 0;
            while (true) {
                if (source[i] == ch) {
                    ck = true;
                    i++;
                    if (i == len) {
                        ans++;
                        i %= len;
                    }
                    break;
                }
                i++;
                if (i == len) {
                    ans++;
                    i %= len;
                }
                times++;
                if (times > len)
                    return -1;
            }
            if (ck == false)
                return -1;
        }
        if (i == 0)
            ans--;
        return ans;
    }
};
