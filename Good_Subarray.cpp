/*
Link:  https://leetcode.com/discuss/interview-question/823513/Google-or-Onsite-or-Good-Subarray

An array is good if all subarrays have atleast 1 element in them whose frequency is 1.

For Example :

Good : 1,2,1
Good: 1,2,5,2,4,3,4
Bad: 1,2,3,1,2,3
Since all subarrays [1], [1,2], [2,1], [1,2,1] have atleast 1 element that occurs once.
Expected Time Complexity : O(NlogN)

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    bool goodSubarray(int st, int ed, const vector<int> &nums) {
        if (st >= ed)
            return true;
        unordered_map<int, int> counter;
        counter.clear();
        for (int i = st; i <= ed; i++) {
            counter[nums[i]]++;
        }
        int ret = true;
        int cnt = 0;
        for (int i = st; i <= ed; i++) {
            if (counter[nums[i]]== 1) {
                cnt++;
                ret = ret & goodSubarray(st, i - 1, nums) & goodSubarray(i + 1, ed, nums);
            }
        }
        if (cnt == 0) {
            return false;
        }
        return ret;
    }

    bool isGoodSubarray(vector<int> nums) {
        return goodSubarray(0, nums.size() - 1, nums);
    }
};


int main() {
    Solution sol = Solution();
    cout << sol.isGoodSubarray({1,2,1}) << endl;
    cout << sol.isGoodSubarray({1,2,5,2,4,3,4}) << endl;
    cout << sol.isGoodSubarray({1,2,3,1,2,3}) << endl;
    cout << sol.isGoodSubarray({1,2,3,1,2,3,4}) << endl;
    return 0;
}

/*
Average: O(nlogn)
Worst case: O(n^2)
*/
