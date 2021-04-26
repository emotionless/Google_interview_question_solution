/*
Link: https://leetcode.com/problems/paint-fence/

You are painting a fence of n posts with k different colors. You must paint the posts following these rules:

Every post must be painted exactly one color.
At most one pair of adjacent fence posts can have the same color.
Given the two integers n and k, return the number of ways you can paint the fence.



Example 1:


Input: n = 3, k = 2
Output: 6
Explanation: All the possibilities are shown.
Note that painting all the posts red or all the posts green is invalid because there can only be at most one pair of adjacent posts that are the same color.
Example 2:

Input: n = 1, k = 1
Output: 1
Example 3:

Input: n = 7, k = 2
Output: 42

*/
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

// Milon
class Solution {
public:

    int solve(int ind) {
        if (ind == 1) {
            return numOfCol;
        } else if (ind == 2) {
            return numOfCol * numOfCol;
        }
        int &ret = dp[ind];
        if (ret != -1) {
            return ret;
        }
        ret = 0;
        ret = solve(ind - 1) * (numOfCol - 1);
        ret += solve(ind - 2) * (numOfCol - 1);
        return ret;
    }

    int numWays(int n, int k) {
        numOfCol = k;
        if (n == 1) {
            return k;
        }
        dp.clear();
        dp.resize(3, 0);
        dp[0] = k;
        dp[1] = k*k;
        for (int i = 2; i < n; i++) {
            dp[i%3] = dp[(i-1)%3] * (k - 1);
            dp[i%3] += dp[(i-2)%3] * (k - 1);
        }
        return dp[(n-1)%3];
    }
private:
    int numOfCol;
    vector<int> dp;
};

int main() {
    Solution sol = Solution();
    cout << sol.numWays(3, 2) << endl;
    cout << sol.numWays(7, 2) << endl;


    return 0;
}
