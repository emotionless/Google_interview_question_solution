/*
Link: https://leetcode.com/problems/closest-leaf-in-a-binary-tree/

We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode" can be represented as arr = ["I","am",happy","with","leetcode"].

Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string pairs similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

Return true if sentence1 and sentence2 are similar, or false if they are not similar.

Two sentences are similar if:

They have the same length (i.e., the same number of words)
sentence1[i] and sentence2[i] are similar.
Notice that a word is always similar to itself, also notice that the similarity relation is transitive. For example, if the words a and b are similar, and the words b and c are similar, then a and c are similar.



Example 1:

Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.
Example 2:

Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","onepiece"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: true
Explanation: "leetcode" --> "platform" --> "anime" --> "manga" --> "onepiece".
Since "leetcode is similar to "onepiece" and the first two words are the same, the two sentences are similar.
Example 3:

Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","hunterXhunter"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: false
Explanation: "leetcode" is not similar to "onepiece".


Constraints:

1 <= sentence1.length, sentence2.length <= 1000
1 <= sentence1[i].length, sentence2[i].length <= 20
sentence1[i] and sentence2[i] consist of lower-case and upper-case English letters.
0 <= similarPairs.length <= 2000
similarPairs[i].length == 2
1 <= xi.length, yi.length <= 20
xi and yi consist of English letters.
*/


// solved by Milon

class Solution {
public:
    string find(string cur) {
        if (par.find(cur) == par.end() || par[cur] == cur)
            return cur;
        return par[cur] = find(par[cur]);
    }
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        for (auto ele : similarPairs) {
            string p1 = find(ele[0]);
            string p2 = find(ele[1]);
            par[p1] = p2;
        }
        int n = sentence1.size();
        if (n != sentence2.size())
            return false;
        for (int i = 0; i < n; i++) {
            if (sentence1[i] == sentence2[i])
                continue;
            string firstStr = find(sentence1[i]);
            string secondStr = find(sentence2[i]);
            if (firstStr != secondStr)
                return false;
        }
        return true;
    }
private:
    unordered_map<string, string> par;
};
