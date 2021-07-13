/*
Link: https://leetcode.com/problems/reverse-words-in-a-string-ii/

Given a character array s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.

Your code must solve the problem in-place, i.e. without allocating extra space.



Example 1:

Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Example 2:

Input: s = ["a"]
Output: ["a"]


Constraints:

1 <= s.length <= 10^5
s[i] is an English letter (uppercase or lowercase), digit, or space ' '.
There is at least one word in s.
s does not contain leading or trailing spaces.
All the words in s are guaranteed to be separated by a single space.
*/

// solved by Milon
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int len = s.size();
        for (int i = 0; i < len; i++) {
            int j = i;
            while (j < len && s[j] != ' ') {
                j++;
            }
            int sz = j - i;
            reverse(s.begin() + i, s.begin() + i + sz);
            i = j;
        }
    }
};
