/*
Link: https://leetcode.com/discuss/interview-question/900991/Google-or-Phone-or-First-Missing-Positive

How do you find smallest non-negative integer that doesn't exist in the given array (including zero)

*array can have duplicates

followup:

can you do it with space complexity O(1)?
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> nums) {
        /*
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        while (i < n && nums[i] < 1) {
            i++;
        }
        if (i >= n || nums[i] != 1) return 1;
        i++;
        for (; i < n; i++) {
            if (nums[i] - nums[i-1] > 1) return nums[i-1] + 1;
        }
        return nums[n-1] + 1;
        */
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != (i+1)) return i+1;
        }
        return n+1;
    }
};

int main() {
        Solution sol = Solution();
        cout << sol.firstMissingPositive({3,4,-1,1}) << endl;

        return 0;
}
