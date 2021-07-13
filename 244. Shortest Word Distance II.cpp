/*
Link: https://leetcode.com/problems/shortest-word-distance-ii/

Design a data structure that will be initialized with a string array, and then it should answer queries of the shortest distance between two different strings from the array.

Implement the WordDistance class:

WordDistance(String[] wordsDict) initializes the object with the strings array wordsDict.
int shortest(String word1, String word2) returns the shortest distance between word1 and word2 in the array wordsDict.


Example 1:

Input
["WordDistance", "shortest", "shortest"]
[[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"], ["makes", "coding"]]
Output
[null, 3, 1]

Explanation
WordDistance wordDistance = new WordDistance(["practice", "makes", "perfect", "coding", "makes"]);
wordDistance.shortest("coding", "practice"); // return 3
wordDistance.shortest("makes", "coding");    // return 1


Constraints:

1 <= wordsDict.length <= 3 * 10^4
1 <= wordsDict[i].length <= 10
wordsDict[i] consists of lowercase English letters.
word1 and word2 are in wordsDict.
word1 != word2
At most 5000 calls will be made to shortest.
*/

// solved by Milon

class WordDistance {
public:
    const int INF = 100000000;

    WordDistance(vector<string>& wordsDict) {
        int sz = wordsDict.size();
        for (int i = 0; i < sz; i++) {
            container[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto word1PosList = container[word1];
        auto word2PosList = container[word2];
        int i = 0, j = 0;
        int sz1 = word1PosList.size();
        int sz2 = word2PosList.size();
        int ans = INF;
        while (i < sz1 && j < sz2) {
            ans = min(ans, abs(word1PosList[i] - word2PosList[j]));
            if (word1PosList[i] < word2PosList[j]) {
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
private:
    unordered_map<string, vector<int>> container;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
