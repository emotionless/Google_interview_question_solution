/*
https://leetcode.com/problems/implement-magic-dictionary/
https://leetcode.com/discuss/interview-question/920913/Google-or-Phone-or-Spell-Checker

*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class MagicDictionary {
public:
    struct node {
        bool isEnd;
        node *nxt[26];
        node() {
            isEnd = false;
            for(int i = 0; i < 26; i++) {
                nxt[i] = nullptr;
            }
        }
    };

    void del(node *cur) {
        if (cur == nullptr) return;
        for(int i = 0; i < 26; i++) {
            if (cur -> nxt[i] != nullptr)
                del(cur -> nxt[i]);
        }
        free (cur);
        return;
    }

    /** Initialize your data structure here. */
    MagicDictionary() {
        del (root);
        root = new node();
    }

    void insert(const string str, int ind, node *cur) {

        if (str.length() == ind) {
            cur -> isEnd = true;
            return;
        }

        int id = str[ind] - 'a';
        if (cur -> nxt[id] == nullptr) {
            cur -> nxt[id] = new node();
        }
        insert(str, ind + 1, cur -> nxt[id]);

        return;
    }

    void buildDict(vector<string> dictionary) {
        node *cur = root;
        for(auto s : dictionary) {
            // cout << s << endl;
            insert(s, 0, cur);
        }
    }

    bool query(const string str, int ind, node *cur, bool isAvailable) {
        if (cur == nullptr) return false;
        if (str.length() == ind) {
            return cur -> isEnd && !isAvailable;
        }

        int id = str[ind] - 'a';
        int ret = 0;
        for(int i = 0; i < 26; i++) {
            if (cur -> nxt[i] != nullptr) {
                if (i == id) {
                    ret += query(str, ind + 1, cur -> nxt[i], isAvailable);
                } else {
                    if (isAvailable) ret += query(str, ind + 1, cur -> nxt[i], false);
                }
            }
        }
        return ret;
    }

    bool search(string searchWord) {
        return query(searchWord, 0, root, true);
    }

private:
    node *root = nullptr;


};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */


 int main() {

    MagicDictionary md = MagicDictionary();
    md.buildDict({"apple", "pineapple"});
    cout << md.search("arple") << endl;

 }
