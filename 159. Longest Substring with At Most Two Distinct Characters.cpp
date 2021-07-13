/*
Link: 159. Longest Substring with At Most Two Distinct Characters

Given a string s, return the length of the longest substring that contains at most two distinct characters.

 

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
 

Constraints:

1 <= s.length <= 104
s consists of English letters.
*/

// solved by Milon
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.length();
        unordered_map<char, int> counter;
        int tot = 0;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            counter[s[i]]++;
            if (counter[s[i]] == 1) {
                tot++;
            }
            while (j < i && tot > 2) {
                counter[s[j]]--;
                if (counter[s[j]] == 0) tot--;
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};