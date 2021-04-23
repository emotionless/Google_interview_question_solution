/*
Problem link: https://leetcode.com/discuss/interview-question/579970/Google-or-Phone-or-Calculate-Column-Width

Solution Author: emotionless
Date: 23 April 2021

Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.


Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>


using namespace std;

class Solution {
public:

    string getSpaces(int cnt, int extra) {
        string ret = "";
        while (cnt--) ret += " ";
        if (extra > 0) ret += " ";
        return ret;
    }

    string makeLine(const vector<string> words, int len, int width) {
        int n = words.size();
        int rest = width - len;
        if (n == 1) {
            string ret = words[0];
            width -= words[0].size();
            while (width--) {
                ret += " ";
            }
            return ret;
        }
        int each = rest / (n-1);
        int extra = rest % (n-1);
        string ret = "";
        ret = words[0];
        for (int i = 1; i < n; i++) {
            ret += getSpaces(each, extra) + words[i];
            extra--;
        }
        return ret;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> tempWords;
        int len = 0;
        int sp = 0;
        for (auto str : words) {
            if ((len+(tempWords.size())+str.length()) > maxWidth) {
                string line = makeLine(tempWords, len, maxWidth);
                ans.push_back(line);
                len = 0;
                tempWords.clear();
                tempWords.push_back(str);
                len = str.length();
            } else {
                tempWords.push_back(str);
                len += str.length();
            }
        }
        string tmp = "";
        tmp = tempWords[0];
        for (int i = 1; i < tempWords.size(); i++) {
            tmp += " " + tempWords[i];
        }
        while (tmp.length() < maxWidth) tmp += " ";
        ans.push_back(tmp);
        return ans;
    }
};


int main() {
    Solution sol = Solution();
    vector<string> arr({"This", "is", "an", "example", "of", "text", "justification."});
    auto ans = sol.fullJustify(arr, 16);
    for (auto v : ans) {
        cout << v << endl;
    }

    return 0;
}

/*

Time complexity:
O(n)
Space complexity:
O(1)

*/
