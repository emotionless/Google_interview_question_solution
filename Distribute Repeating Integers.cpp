/*
Link: https://leetcode.com/discuss/interview-question/967367/Google-or-on-site-or-find-array-of-integer-is-fit-to-the-other

You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:

The ith customer gets exactly quantity[i] integers,
The integers the ith customer gets are all equal, and
Every customer is satisfied.
Return true if it is possible to distribute nums according to the above conditions.



Example 1:

Input: nums = [1,2,3,4], quantity = [2]
Output: false
Explanation: The 0th customer cannot be given two different integers.
Example 2:

Input: nums = [1,2,3,3], quantity = [2]
Output: true
Explanation: The 0th customer is given [3,3]. The integers [1,2] are not use

*/

class Solution {
public:

    bool solve(int ind, int mask, const vector<int> &arr, const vector<int> &quantity) {
        int m = quantity.size();
        if (mask == ((1<<m) - 1)) {
            return true;
        }
        if (ind == arr.size()) {
            return false;
        }
        int &ret = dp[ind][mask];
        if (ret != -1)
            return ret;
        ret = 0;
        for (int i = 0; i < (1<<m); i++) {
            if (i&mask)
                continue;
            int tot = arr[ind];
            for (int j = 0; j < m; j++) {
                if (i&(1<<j)) {
                    tot -= quantity[j];
                }
            }
            if (tot >= 0) {
                ret = ret + solve(ind + 1, mask | i, arr, quantity);
            }
        }

        return ret;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        int m = quantity.size();
        for (auto num : nums) {
            counter[num]++;
        }
        vector<int> vec;
        for (auto it : counter) {
            vec.push_back(it.second);
        }
        int n = vec.size();
        dp.resize(n, vector<int> (1<<m, -1));
        return solve(0, 0, vec, quantity);
    }
private:
    vector<vector<int>> dp;
    unordered_map<int, int> counter;
};
