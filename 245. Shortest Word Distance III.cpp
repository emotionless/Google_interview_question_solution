/*
Link: https://leetcode.com/problems/shortest-word-distance-iii/

Given an array of strings wordsDict and two strings that already exist in the array word1 and word2, return the shortest distance between these two words in the list.

Note that word1 and word2 may be the same. It is guaranteed that they represent two individual words in the list.



Example 1:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "coding"
Output: 1
Example 2:

Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"], word1 = "makes", word2 = "makes"
Output: 3


Constraints:

1 <= wordsDict.length <= 10^5
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
*/

// solved by Milon

class Solution {
public:
    const int INF = 100000000;

    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int word1Pos = -INF;
        int word2Pos = -INF;
        int sz = wordsDict.size();
        int ans = INF;
        for (int i = 0; i < sz; i++) {
            if (wordsDict[i] == word1) {
                ans = min(ans, i - word2Pos);
                word1Pos = i;
            }
            if (wordsDict[i] == word2) {
                if (word1Pos != i)
                    ans = min(ans, i - word1Pos);
                word2Pos = i;
            }
        }
        return ans;
    }
};


// solved by Milon

class Solution {
public:
    const int INF = 100000000;

    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, int> lastPos;
        int sz = wordsDict.size();
        lastPos[word1] = -INF;
        lastPos[word2] = -INF;
        int ans = INF;
        for (int i = 0; i < sz; i++) {
            if (wordsDict[i] == word1) {
                ans = min(ans, i - lastPos[word2]);
                lastPos[word1] = i;
            } else if (wordsDict[i] == word2) {
                ans = min(ans, i - lastPos[word1]);
                lastPos[word2] = i;
            }
        }
        return ans;
    }
};
