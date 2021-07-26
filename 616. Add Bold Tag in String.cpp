/*
Link: https://leetcode.com/problems/add-bold-tag-in-string/

You are given a string s and an array of strings words. You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words. If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag. If two substrings wrapped by bold tags are consecutive, you should combine them.

Return s after adding the bold tags.



Example 1:

Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"
Example 2:

Input: s = "aaabbcc", words = ["aaa","aab","bc"]
Output: "<b>aaabbc</b>c"


Constraints:

1 <= s.length <= 1000
0 <= words.length <= 100
1 <= words[i].length <= 1000
s and words[i] consist of English letters and digits.
All the values of words are unique.


Note: This question is the same as 758: https://leetcode.com/problems/bold-words-in-string/
*/

// solved by Milon

class Solution {
public:

    struct node {
        bool isEnd;
        node *next[62];
        node() {
            isEnd = false;
            for (int i = 0; i < 62; i++) {
                next[i] = nullptr;
            }
        }
    } *root;

    int getId(char ch) {
        if (ch < 65)
            return ch - '0' + 52;
        else if (ch < 98)
            return ch - 'A' + 26;
        return ch - 'a';
    }

    void insert(string &str) {
        node *cur = root;
        for (auto ch : str) {
            int id = getId(ch);
            if (cur->next[id] == nullptr)
                cur->next[id] = new node();
            cur = cur->next[id];
        }
        cur->isEnd = true;
    }
    int search(int st, const string &str) {
        node *cur = root;
        int mxInd = -1;
        for (int i = st; i < str.length(); i++) {
            int id = getId(str[i]);
            if (cur->next[id] == nullptr) {
                break;
            }
            cur = cur->next[id];
            if (cur->isEnd == true)
                mxInd = i;
        }
        return mxInd;
    }

    string addBoldTag(string s, vector<string>& words) {
        root = new node();
        for (auto word : words) {
            insert(word);
        }
        int len = s.length();
        vector<bool> vis(len, false);

        for (int i = 0; i < len; i++) {
            int j = search(i, s);
            for (int k = i; k <= j; k++) {
                vis[k] = true;
            }
        }
        string ans = "";
        for (int i = 0; i < len; i++) {
            if (vis[i] == true) {
                int j = i;
                ans += "<b>";
                while (j < len && vis[j] == true) {
                    ans += s[j];
                    j++;
                }
                ans += "</b>";
                i = j - 1;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};
