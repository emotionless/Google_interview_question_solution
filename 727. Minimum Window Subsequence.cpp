/*
Problem link: https://leetcode.com/problems/minimum-window-subsequence/

Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input:
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation:
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.


Note:

All the strings in the input will only contain lowercase letters.
The length of S will be in the range [1, 20000].
The length of T will be in the range [1, 100].

*/

// Solve by Milon

class Solution {
public:

    int solve(int ind1, int ind2, const string &S, const string &T) {
        if (T.length() == ind2) return 0;
        if (S.length() == ind1) return 2*S.length();

        int &ret = dp[ind1][ind2];
        if (ret != -1) return ret;
        ret = 2*S.length();

        ret = solve(ind1 + 1, ind2, S, T);
        if (S[ind1] == T[ind2])
            ret = min(ret, solve(ind1 + 1, ind2 + 1, S, T));
        ret += 1;

        return ret;
    }

    string minWindow(string S, string T) {
        int n = S.length();
        int m = T.length();
        dp.resize(n, vector<int>(m, -1));


        solve(0, 0, S, T);


        int pos = -1;
        int res = 2*S.length();
        for(int i = 0; i < n; i++) {
            if (dp[i][0] < res) {
                res = dp[i][0];
                pos = i;
            }
        }
        if (pos == -1)
            return "";
        return S.substr(pos, res);
    }

private:
    vector<vector<int>> dp;
};
