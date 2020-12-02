/*
Problem link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
Solved by: emotionless

Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.



Example 1:

Input: words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
Output: 23
Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
Words "dad" and "dog" only get a score of 21.

Example 2:

Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with a score of 27.
Word "xxxz" only get a score of 25.

*/


class Solution {
public:
    int counter[26];
    int ans = 0;
    void solve(int ind, const vector<string> &words, const vector<int> &score, int sum) {
        if (ind == words.size()) {
            ans = max(ans, sum);
            return;
        }

        solve(ind + 1, words, score, sum);
        bool check = false;
        int cnt[26] = {0};
        for(auto ch : words[ind]) {
            cnt[ch-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if (cnt[i] > counter[i]) {
                check = true;
                break;
            }
        }
        if (check == false) {
            int s = 0;
            for(auto ch : words[ind]) {
                s += score[ch-'a'];
                counter[ch-'a']--;
            }
            solve(ind + 1, words, score, sum + s);
            for(auto ch : words[ind]) {
                counter[ch-'a']++;
            }
        }
        return;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, const vector<int>& score) {
        memset(counter, 0, sizeof counter);
        for(auto ch : letters) {
            counter[ch-'a']++;
        }
        ans = 0;
        solve(0, words, score, 0);

        return ans;
    }
};
