/*
Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted on the screen.

Note:

A word cannot be split into two lines.
The order of words in the sentence must remain unchanged.
Two consecutive words in a line must be separated by a single space.
Total words in the sentence won't exceed 100.
Length of each word is greater than 0 and won't exceed 10.
1 <= rows, cols <= 20,000.
Example 1:

Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output:
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.
Example 2:

Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output:
2

Explanation:
a-bcd-
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.
Example 3:

Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output:
1

*/


// Solved by Milon

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        int nextStart[n];
        int times[n];

        memset(times, 0, sizeof times);

        for(int i = 0; i < n; i++) {
            int cur = i;
            int curLen = 0;
            int cnt = 0;
            while((curLen + sentence[cur].length()) <= cols) {
                curLen += sentence[cur].length() + 1;
                cur++;
                if (cur == n) {
                    cnt++;
                    cur = 0;
                }
            }
            times[i] = cnt;
            nextStart[i] = cur;
        }

        int ans = 0;
        int cur = 0;
        for(int i = 1; i <= rows; i++) {
            ans += times[cur];
            cur = nextStart[cur];
        }

        return ans;
    }
};
