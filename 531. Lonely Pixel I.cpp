/*
Link: https://leetcode.com/problems/lonely-pixel-i/

Given an m x n picture consisting of black 'B' and white 'W' pixels, return the number of black lonely pixels.

A black lonely pixel is a character 'B' that located at a specific position where the same row and same column don't have any other black pixels.



Example 1:


Input: picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
Output: 3
Explanation: All the three 'B's are black lonely pixels.
Example 2:


Input: picture = [["B","B","B"],["B","B","B"],["B","B","B"]]
Output: 0


Constraints:

m == picture.length
n == picture[i].length
1 <= m, n <= 500
picture[i][j] is 'W' or 'B'.
*/

// solved by Milon

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        if (n == 0)
            return 0;
        int m = picture[0].size();
        if (m == 0)
            return 0;
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B')
                    row[i]++, col[j]++;
            }
        }
        int tot = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1)
                    tot++;
            }
        }
        return tot;
    }
};
