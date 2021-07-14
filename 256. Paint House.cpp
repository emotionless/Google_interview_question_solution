/*
Link: https://leetcode.com/problems/paint-house/

There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.



Example 1:

Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.
Example 2:

Input: costs = [[7,6,2]]
Output: 2


Constraints:

costs.length == n
costs[i].length == 3
1 <= n <= 100
1 <= costs[i][j] <= 20

*/

// solved by Milon
class Solution {
public:

    int solve(int ind, int pre, const vector<vector<int>> &costs) {
        if (ind == costs.size()) {
            return 0;
        }
        int &ret = dp[ind][pre];
        if (ret != -1)
            return ret;
        ret = INT_MAX;
        for (int i = 0; i < 3; i++) {
            if (i == pre)
                continue;
            ret = min(ret, costs[ind][i] + solve(ind + 1, i, costs));
        }
        return ret;
    }

    int minCost(vector<vector<int>>& costs) {
        // dp.resize(costs.size(), vector<int>(3, -1));
        // return min(solve(0, 0, costs), solve(0, 1, costs));
        int n = costs.size();
        dp.resize(3, vector<int>(3, INT_MAX));
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < 3; j++) {
                int f = (j + 1) % 3;
                int s = (j - 1 + 3) % 3;
                dp[i%3][j] = costs[i][j] + min(((i+1) < n? dp[(i+1)%3][f]:0), ((i+1) < n? dp[(i+1)%3][s]:0));
            }
        }
        return min(dp[0][0], min(dp[0][1], dp[0][2]));
    }
private:
    vector<vector<int>> dp;
};
