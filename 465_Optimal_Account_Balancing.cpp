/*
Problem link: https://leetcode.com/problems/optimal-account-balancing/

A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill's lunch for $10.
Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z.
Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].

Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.

Note:

A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.
Example 1:

Input:
[[0,1,10], [2,0,5]]

Output:
2

Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.

Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
Example 2:

Input:
[[0,1,10], [1,0,1], [1,2,5], [2,0,5]]

Output:
1

Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.

Therefore, person #1 only need to give person #0 $4, and all debt is settled.

*/

// solved by Milon

class Solution {
public:

    int solve(int ind) {
        if (ind == num.size()) return 0;
        int cur = num[ind];
        if (cur == 0) return solve(ind + 1);

        int ret = INT_MAX;
        for(int i = ind + 1; i < num.size(); i++) {
            int nxt = num[i];
            if (cur * nxt < 0) {
                num[i] += cur;
                ret = min(ret, 1 + solve(ind + 1));
                num[i] -= cur;
                if (cur + nxt == 0) break;
            }
        }
        return ret;
    }

    int minTransfers(vector<vector<int>>& transactions) {
        for(auto v : transactions) {
            debtAmount[v[0]] += v[2];
            debtAmount[v[1]] -= v[2];
        }

        for(auto it : debtAmount) {
            if (it.second != 0) num.push_back(-it.second);
        }
        // sort(num.begin(), num.end());
        int ans = solve(0);

        return ans;
    }

private:
    unordered_map<int, int> debtAmount;
    vector<int> num;
};
