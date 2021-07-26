/*
Link: https://leetcode.com/problems/maximum-distance-in-arrays/

You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.



Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
Example 3:

Input: arrays = [[1],[2]]
Output: 1
Example 4:

Input: arrays = [[1,4],[0,5]]
Output: 4


Constraints:

m == arrays.length
2 <= m <= 10^5
1 <= arrays[i].length <= 500
-10^4 <= arrays[i][j] <= 10^4
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.
*/


// solved by Milon

class Solution {
public:
    /*Sol1:*/
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        vector<int> mn(n, INT_MAX);
        mn[n-1] = arrays.back()[0];
        for (int i = n-2; i >= 0; i--) {
            mn[i] = min(mn[i+1], arrays[i][0]);
        }
        int ans = arrays[0].back() - mn[1];
        int preMn = arrays[0][0];
        for (int i = 1; i < n-1; i++) {
            ans = max(ans, arrays[i].back() - min(preMn, mn[i+1]));
            preMn = min(preMn, arrays[i][0]);
        }
        ans = max(ans, arrays[n-1].back() - preMn);

        return ans;
    }

    /*Sol2:*/
    int maxDistance(vector<vector<int>>& arr) {
        int n = arr.size();
        int mn = arr[0][0];
        int mx = arr[0].back();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, arr[i].back() -  mn);
            ans = max(ans, mx - arr[i][0]);
            mn = min(mn, arr[i][0]);
            mx = max(mx, arr[i].back());
        }
        return ans;
    }
};
