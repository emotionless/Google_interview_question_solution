/*
Link: https://leetcode.com/problems/generalized-abbreviation/

A word's generalized abbreviation can be constructed by taking any number of non-overlapping substrings and replacing them with their respective lengths. For example, "abcde" can be abbreviated into "a3e" ("bcd" turned into "3"), "1bcd1" ("a" and "e" both turned into "1"), and "23" ("ab" turned into "2" and "cde" turned into "3").

Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.



Example 1:

Input: word = "word"
Output: ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
Example 2:

Input: word = "a"
Output: ["1","a"]


Constraints:

1 <= word.length <= 15
word consists of only lowercase English letters.
*/

class Solution {
public:
    vector<string> generate(int index, bool isWord, const string &word) {
        if (index == word.size()) {
            return {""};
        }
        if (dp.find(make_pair(index, isWord)) != dp.end()) {
            return dp[make_pair(index, isWord)];
        }
        vector<string> &ret = dp[make_pair(index, isWord)];
        if (isWord) {
            string str = "";
            for (int i = index; i < word.size(); i++) {
                str += word[i];
                auto wordList = generate(i + 1, false, word);
                for (auto ele : wordList) {
                    ret.push_back(str + ele);
                }
            }
        } else {
            for (int i = index; i < word.size(); i++) {
                auto wordList = generate(i + 1, true, word);
                for (auto ele : wordList) {
                    ret.push_back(to_string(i - index + 1) + ele);
                }
            }
        }
        return ret;
    }

    vector<string> generateAbbreviations(string word) {
        auto res = generate(0, false, word);
        vector<string> ret;
        ret = res;
        res = generate(0, true, word);
        for (auto ele : res) {
            ret.push_back(ele);
        }
        return ret;
    }
private:
    map<pair<int, bool>, vector<string>> dp;
};
