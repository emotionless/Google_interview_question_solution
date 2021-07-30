/*
Link: https://leetcode.com/discuss/interview-question/1038963/Google-or-onsite-or-new-grad

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

HINT: overlapping problem

I couldn't come up with the solution. Please if anyone has some approach please let know. Also, if anybody couldn't get the question please let me know through comments I will try to improvise it.

Edits: Array can contain negitives also. Binary search solution won't work in that case
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
const int INF = 1000000;
vector<vector<int>> dp;

int solve(int ind, int m, const vector<int> &nums) {
    if (ind == nums.size()) {
        if (m == 0) return 0;
        return INF;
    }
    int &ret = dp[ind][m];
    if (ret != -1) return ret;
    ret = INF;
    int sum = 0;
    for (int i = ind; i < nums.size(); i++) {
        sum += nums[i];
        ret = min(ret, max(sum, solve(i + 1, m - 1, nums)));
    }

    return ret;
}

int splitArray(vector<int> &nums, int m) {
    int n = nums.size();
    dp.resize(n, vector<int>(m + 1, -1));

    return solve(0, m, nums);
}

int main() {

    vector<int> nums {1, 3, 9, 2, 7, 8};
    cout << splitArray(nums, 3) << endl;

    return 0;
}
