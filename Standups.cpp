/*
Link: https://leetcode.com/discuss/interview-question/978112/Google-or-L4-or-Onsite-SWE-or-Standups

N people are formed in a circle during standup. The first person starts the conversation and then calls on someone non-adjacent to them to go next. This process repeats until everyone has spoken only once. Given N, how many different combinations can standup take place?

Example: Given 5, return 2.
Explanation: Possible pathes are 1->4->2->5->3 or 1->3->5->2->4 (Shown in diagram)
image

Example 2: Given 4, return 0.
Explanation: No possible way to complete standup.

Example 3: Given 9, return 4106.

Notes: Minimum input was given as 1.
Can we do better then 2^N?

Follow-up: Instead of given N, the input is given as an array where array[i] represents how long the person will be speaking for. This number is multiplied by their order they speak in.

1st person to go speaks for array[i] * 1, array[i] * 2 for second, array[i] * 3 for third, etc..
Return the minimum duration of the standup with the conversation starting at array[0].

If standup cannot be completed, return -1.

Follow-up Notes: Array is guaranteed to have atleast one element for follow-up. All elements in the array are positive integers.

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>


using namespace std;

class Solution {
public:

    int solve(int ind, const int mask, const int &n, vector<vector<int>> &dp) {
        if (mask == ((1<<n) - 1)) {
            return 1;
        }
        int &ret = dp[ind][mask];
        if (ret != -1) return ret;
        ret = 0;
        for (int i = 0; i < n; i++) {
            if (abs(ind - i) <= 1 || abs(ind - i) == (n-1) || mask&(1<<i)) continue;
            ret += solve(i, mask | (1<<i), n, dp);
        }
        return ret;
    }

    int numberOfWays(int n) {
        vector<vector<int>> dp(n, vector<int>(1<<n, -1));
        return solve(0, 1, n, dp);
    }

};

int main() {
    Solution sol = Solution();
    cout << sol.numberOfWays(4) << endl;
    cout << sol.numberOfWays(5) << endl;
    cout << sol.numberOfWays(9) << endl;
    cout << sol.numberOfWays(13) << endl;


    return 0;
}
