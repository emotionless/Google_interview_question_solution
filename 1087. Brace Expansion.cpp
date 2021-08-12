/*
Problem link: https://leetcode.com/problems/brace-expansion/


You are given a string s representing a list of words. Each letter in the word has one or more options.

If there is one option, the letter is represented as is.
If there is more than one option, then curly braces delimit the options. For example, "{a,b,c}" represents options ["a", "b", "c"].
For example, if s = "a{b,c}", the first character is always 'a', but the second character can be 'b' or 'c'. The original list is ["ab", "ac"].

Return all words that can be formed in this manner, sorted in lexicographical order.



Example 1:

Input: s = "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
Example 2:

Input: s = "abcd"
Output: ["abcd"]


Constraints:

1 <= s.length <= 50
s consists of curly brackets '{}', commas ',', and lowercase English letters.
s is guaranteed to be a valid input.
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.

*/

// solved by Milon

class Solution {
public:

    vector<string> backTrack(int ind, const vector<vector<char>> &container) {
        if (ind == container.size()) {
            return {""};
        }
        vector<string> ret;
        vector<string> nextAns = backTrack(ind + 1, container);
        for (auto ch : container[ind]) {
            for (auto str : nextAns) {
                ret.push_back(ch + str);
            }
        }
        return ret;
    }

    vector<string> expand(string s) {
        int len = s.size();
        vector<vector<char>> container;
        for (int i = 0; i < len; i++) {
            if (s[i] == '{') {
                i++;
                vector<char> curContainer;
                while (s[i] != '}') {
                    if (s[i] != ',') {
                        curContainer.push_back(s[i]);
                    }
                    i++;
                }
                sort(curContainer.begin(), curContainer.end());
                container.push_back(curContainer);
            } else {
                container.push_back({s[i]});
            }
        }
        return backTrack(0, container);
    }
};
