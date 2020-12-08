/*
Problem link:https://leetcode.com/problems/word-abbreviation/

Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
If the abbreviation doesn't make the word shorter, then keep it as original.
Example:
Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]

*/


// Solved by Milon

class Solution {
public:

    int match(const string &a, const string &b) {
        int len = a.length();
        for(int i = 0; i < len; i++) {
            if (a[i] != b[i]) return i;
        }

        return len;
    }

    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<string, vector<string>> container;
        int ind = 0;
        map<string, int> pos;

        for(auto v : dict) {
            pos[v] = (ind++);
            int len = v.length();
            if (len <= 3) {
                container[v].push_back(v);
            } else {
                string tmp = v[0] + to_string(len-2) + v[len-1] + "";
                auto &c = container[tmp];
                c.push_back(v);
            }
        }
        for(auto &it : container) {
            sort(it.second.begin(), it.second.end());

            auto wordList = it.second;
            int sz = wordList.size();
            for(int i = 0; i < sz; i++) {
                int mx = 0;
                // previous compare
                if (i) {
                    mx = max(mx, match(wordList[i], wordList[i-1]));
                }
                // next compare
                if ((i+1) < sz) {
                    mx = max(mx, match(wordList[i], wordList[i+1]));
                }
                int len = wordList[i].length();
                string abWord = wordList[i];
                mx++;
                if ((mx+1+1) >= len) {
                    // do nothing
                } else {
                    string tmp = abWord.substr(0, mx) + to_string(len - mx - 1) + abWord[len-1];
                    dict[ pos[abWord] ] = tmp;
                }
            }
        }
        return dict;
    }
};
