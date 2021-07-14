/*
Link:  https://leetcode.com/problems/factor-combinations/

Numbers can be regarded as the product of their factors.

For example, 8 = 2 x 2 x 2 = 2 x 4.
Given an integer n, return all possible combinations of its factors. You may return the answer in any order.

Note that the factors should be in the range [2, n - 1].



Example 1:

Input: n = 1
Output: []
Example 2:

Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]
Example 3:

Input: n = 37
Output: []
Example 4:

Input: n = 32
Output: [[2,16],[4,8],[2,2,8],[2,4,4],[2,2,2,4],[2,2,2,2,2]]


Constraints:

1 <= n <= 10^7
*/

// solved by Milon
class Solution {
public:

    vector<vector<int>> solve(int n, int st) {
        int sq = sqrt(n);
        vector<vector<int>> ret;
        for (int i = st; i <= sq; i++) {
            if (n%i == 0) {
                auto tmp = solve(n/i, i);
                for (auto v : tmp) {
                    v.push_back(i);
                    ret.push_back(v);
                }
            }
        }
        ret.push_back({n});
        return ret;
    }

    vector<vector<int>> getFactors(int n) {
        auto res = solve(n, 2);
        res.pop_back();
        return res;
    }
};

/*

12
2 6{2, 3}
3 4

*/
