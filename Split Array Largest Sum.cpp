/*
Problem link: https://leetcode.com/discuss/interview-question/1038963/Google-or-onsite-or-new-grad

Solution Author: emotionless
Date: 23 April 2021


Given an array of integers and a number m. We can create m subarrays using the input array. The max sum of each subarrays out of each possibilities are taken. Return the minimum number out of them.

Eg: [1 3 9 2 7 8]
m=2

Possibilities------Sum---Max
[1] [3 9 3 7 8]--- 1, 30----30
[1 3][ 9 2 7 8]--- 4, 27----27
[1 3 9][ 2 7 8]---13, 17----17
[1 3 9 2][ 7 8]---15, 15----15
[1 3 9 2 7][ 8]---22, 8----22

ans: 15 (as 15 is min of the all maximum sums)
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>


using namespace std;

class Solution {
public:
    const int INF = 1000000001;
    int solve(int ind, int m, const vector<int> &nums) {
        if (ind == nums.size()) {
            if (m == 0) return 0;
            return INF;
        }
        if (m == 0) return INF;
        int &ret = dp[ind][m];
        if (ret != -1) return ret;
        ret = INF;
        int sum = 0;
        for (int i = ind; i < nums.size(); i++) {
            sum += nums[i];
            ret = min(ret, max(sum, solve(i+1, m-1, nums)));
        }
        return ret;
    }

    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(0, m, nums);
    }
private:
    vector<vector<int>> dp;
};


int main() {
    Solution sol = Solution();
    vector<int> arr({1, 3, 9, 2, 7, 8});
    auto ans = sol.splitArray(arr, 2);
    cout << ans << endl;

    return 0;
}

/*

Time complexity:
O(n)
Space complexity:
O(1)

*/
