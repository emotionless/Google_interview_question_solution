/*
Problem link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.

*/

// solved by Milon

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(const string s, int k) {
        int len = s.length();
        int j = 0;
        if (!k) return 0;
        int ans = 0;
        unordered_map<char, int> counter;
        for(int i = 0; i < len; i++) {
            while(j < len && (counter.size() < k || counter.find(s[j]) != counter.end())) {
                counter[s[j]]++;
                j++;
            }
            ans = max(ans, j - i);
            counter[s[i]]--;
            if (counter[s[i]] == 0) {
                counter.erase(s[i]);
            }
        }
        return ans;
    }
};
