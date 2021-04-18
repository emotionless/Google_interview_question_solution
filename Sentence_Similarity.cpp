/*
Link: https://leetcode.com/discuss/interview-question/698670/Google-or-Phone-screen-or-Sentence-similarity-(variant)-June-2020

Question
Given a list of synonym pairs, write a function to determine which pairs of sentences in an input list of such queries are synonyms. Two sentences are synonyms if their words are equal or synonyms in order.

Example
Input
synonym_pairs: [('great', 'good'), ('great', 'excellent'), ('good', 'fine')]
sentence_pairs: [('Google is a good company', 'Google is a great company'), ('My performance is bad', 'My performance is poor')]
Output
result: [True, False]

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    Solution(vector<pair<string, string>> synonym_pairs) {
        for (auto syn : synonym_pairs) {
            synonyms.insert(syn.first + syn.second);
            swap(syn.first, syn.second);
            synonyms.insert(syn.first + syn.second);
        }
    }

    vector<bool> checkSimilarity(vector<pair<string, string>> sentence_pairs) {
        vector<bool> ans;
        for (auto p : sentence_pairs) {
            ans.push_back(isSimilarSentence(p.first, p.second));
        }
        return ans;
    }

private:

    unordered_set<string> synonyms;

    bool isSimilarSentence(string str1, string str2) {
        stringstream ss1(str1), ss2(str2);
        vector<string> vec1, vec2;
        string tmp1, tmp2;
        while (ss1 >> tmp1) {
            vec1.push_back(tmp1);
        }
        while (ss2 >> tmp2) {
            vec2.push_back(tmp2);
        }
        if (vec1.size() != vec2.size()) return false;
        for (int i = 0; i < vec1.size(); i++) {
            if (vec1[i] != vec2[i] && synonyms.find(vec1[i] + vec2[i]) == synonyms.end()) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution sl = Solution({{"great", "good"}, {"great", "excellent"}, {"good", "fine"}});
    auto ans = sl.checkSimilarity({{"Google is a good company", "Google is a great company"}, {"My performance is bad", "My performance is poor"}});
    for (auto v : ans) {
        cout << v << endl;
    }
    return 0;
}
