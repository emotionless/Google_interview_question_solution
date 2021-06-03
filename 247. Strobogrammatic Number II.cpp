/*
Problem link: https://leetcode.com/problems/strobogrammatic-number-ii/

Given an integer n, return all the strobogrammatic numbers that are of length n. You may return the answer in any order.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).



Example 1:

Input: n = 2
Output: ["11","69","88","96"]
Example 2:

Input: n = 1
Output: ["0","1","8"]


Constraints:

1 <= n <= 14

*/

// Milon

class Solution {
public:

    string rotatedStr(string str) {
        for (auto &ch : str) {
            ch = rotatedDigit[ch];
        }
        reverse(str.begin(), str.end());
        return str;
    }

    void solve(int rem, const string &cur, vector<string> &ans) {
        if (rem == 0) {
            string tmp = rotatedStr(cur);
            ans.push_back(cur + tmp);
            return;
        } else if (rem == 1) {
            string tmp = rotatedStr(cur);
            ans.push_back(cur + '0' + tmp);
            ans.push_back(cur + '1' + tmp);
            ans.push_back(cur + '8' + tmp);
            return;
        }
        for (auto d : digits) {
            if (d == '0' && cur == "")
                continue;
            solve(rem - 2, cur + d, ans);
        }
    }

    vector<string> findStrobogrammatic(int n) {
        rotatedDigit['0'] = '0';
        rotatedDigit['1'] = '1';
        rotatedDigit['6'] = '9';
        rotatedDigit['8'] = '8';
        rotatedDigit['9'] = '6';
        vector<string> ans;
        string cur = "";
        solve(n, cur, ans);
        return ans;
    }
private:
    unordered_map<char, char> rotatedDigit;
    vector<char> digits {'0', '1', '6', '8', '9'};
};
