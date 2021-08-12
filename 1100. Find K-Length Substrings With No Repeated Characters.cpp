/*
Problem link: https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/

Given a string s and an integer k, return the number of substrings in s of length k with no repeated characters.



Example 1:

Input: s = "havefunonleetcode", k = 5
Output: 6
Explanation: There are 6 substrings they are: 'havef','avefu','vefun','efuno','etcod','tcode'.
Example 2:

Input: s = "home", k = 5
Output: 0
Explanation: Notice k can be larger than the length of s. In this case, it is not possible to find any substring.


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
1 <= k <= 104

*/

// solved by Milon

class Solution {
public:
    int numKLenSubstrNoRepeats(const string &s, int k) {
        int len = s.size();
        unordered_map<char, int> counter;
        for (int i = 0; i < k-1; i++) {
            counter[s[i]]++;
        }
        int ans = 0;
        for (int i = 0; (i+k-1) < len; i++) {
            char ch = s[i + k - 1];
            counter[ch]++;
            int tot = counter.size();
            if (tot == k) {
                ans++;
            }
            ch = s[i];
            counter[ch]--;
            if (counter[ch] == 0) {
                tot--;
                counter.erase(ch);
            }
        }
        return ans;
    }
};
