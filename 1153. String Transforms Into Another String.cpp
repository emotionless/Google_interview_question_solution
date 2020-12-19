/*
Problem link: https://leetcode.com/problems/string-transforms-into-another-string/

Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.

Return true if and only if you can transform str1 into str2.



Example 1:

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.
Example 2:

Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.


Constraints:

1 <= str1.length == str2.length <= 104
str1 and str2 contain only lowercase English letters.


*/

// Solved by Milon

class Solution {
public:
    bool canConvert(string str1, string str2) {
        int len = str1.length();
        if (str1 == str2) return true;
        unordered_map<char, int> hash, vis;
        for(int i = 0; i < len; i++) {
            char cur = str1[i];
            vis[str2[i]] = str2[i];
            if (hash.find(cur) != hash.end()) {
                cur = hash[cur];
                if (cur != str2[i]) return false;
            } else {
                hash[cur] = str2[i];
            }
        }

        if (vis.size() == 26) {
            return false;
        }
        return true;
    }
};
