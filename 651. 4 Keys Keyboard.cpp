/*
Link: https://leetcode.com/problems/4-keys-keyboard/

Imagine you have a special keyboard with the following keys:

A: Print one 'A' on the screen.
Ctrl-A: Select the whole screen.
Ctrl-C: Copy selection to buffer.
Ctrl-V: Print buffer on screen appending it after what has already been printed.
Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.



Example 1:

Input: n = 3
Output: 3
Explanation: We can at most get 3 A's on screen by pressing the following key sequence:
A, A, A
Example 2:

Input: n = 7
Output: 9
Explanation: We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V


Constraints:

1 <= n <= 50
*/
// solved by Milon
class Solution {
public:

    int solve(int len, int buffer, int remaining) {
        if (remaining == 0)
            return len;
        int ret = solve(len + 1, buffer, remaining - 1);
        ret = max(ret, solve(len + buffer, buffer, remaining - 1));
        if (remaining >= 3) {
            ret = max(ret, solve(len*2, len, remaining - 3));
        }
        return ret;
    }


    int maxA(int n) {
        if (dp.find(n) != dp.end())
            return dp[n];
        int &ret = dp[n];
        ret = n;
        for (int i = 1; i <= (n - 3); i++) {
            ret = max(ret, maxA(i) * (n - i - 1));
        }
        return ret;
    }
private:
    unordered_map<int, int> dp;
};
