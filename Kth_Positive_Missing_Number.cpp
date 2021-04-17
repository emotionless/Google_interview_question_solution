/*
Link: https://leetcode.com/discuss/interview-question/723230/Google-or-Phone-or-Kth-missing-number

Given a strictly ascending array of positive integers, output the Kth number that is missing from it.

For example:

(2, 14, 16, 17) K = 4 output: 5 (explanation: missing numbers are 1,3,4,5,6,.. and find the Kth missing number which is 5 as K = 4)
(8, 9) K = 1 output: 1
(8, 9) K=1000000 output:1000002
Expected runtime O(log N) where N = array length

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int> arr, int k) {
        int n = arr.size();
        int st = 0, ed = n - 1, pos = -1;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            int missing = arr[mid] - mid - 1;
            if (missing <= k) {
                pos = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        if (pos == -1) return k;
        int need = k - (arr[pos] - pos - 1);
        return arr[pos] + need;
    }
};


int main() {
    Solution sl = Solution();
    cout << sl.findKthPositive({2,3,4,7,11}, 5) << endl;
    cout << sl.findKthPositive({2, 14, 16, 17}, 4) << endl;
    cout << sl.findKthPositive({1,2,3,4}, 2) << endl;

    return 0;
}
