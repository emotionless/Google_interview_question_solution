/*
Link: https://leetcode.com/discuss/interview-question/704810/Google-or-Phone-or-Longest-Subarray-Midpoint

Given an array of 1s and 0s. Your method should return midpoint of the longest subarray of zeros.
Given 0100010 => the longest subarray is 0100010 => you should return the index of 0100010 => return 3.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int longestSuarrayMidpoint(string str) {
        int n = str.size();
        int sum = 0, pos = -1, ans = -1;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                sum++;
                if (sum > ans) {
                    ans = sum;
                    pos = i;
                }
            } else {
                sum = 0;
            }
        }
        if (pos == -1) return -1;
        return pos - ans / 2;
    }
};


int main() {
    Solution sl = Solution();
    cout << sl.longestSuarrayMidpoint("0100010") << endl;

    return 0;
}
