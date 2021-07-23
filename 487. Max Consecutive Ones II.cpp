/*
Link: https://leetcode.com/problems/max-consecutive-ones-ii/

Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.



Example 1:

Input: nums = [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of consecutive 1s is 4.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 4


Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.


Follow up: What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
*/

// solved by Milon

class Solution {
public:

    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, cnt = 0, prev = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cnt++;
                mx = max(mx, prev + cnt);
            } else {
                mx = max(mx, cnt + 1);
                prev = cnt + 1;
                cnt = 0;
            }
        }
        return mx;
    }
    /*
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int mx = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                cnt++;
                mx = max(mx, cnt);
                continue;
            }
            int j = i + 1;
            while (j < n && nums[j] == 1) {
                j++;
            }
            mx = max(mx, cnt + 1 + (j - i - 1));
            cnt = 0;
        }
        return mx;
    }
    */
};
