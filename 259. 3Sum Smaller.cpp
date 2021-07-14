/*
Link: https://leetcode.com/problems/paint-house/

Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.



Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]
Example 2:

Input: nums = [], target = 0
Output: 0
Example 3:

Input: nums = [0], target = 0
Output: 0


Constraints:

n == nums.length
0 <= n <= 3500
-100 <= nums[i] <= 100
-100 <= target <= 100

*/

// solved by Milon

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int k = n - 1;
            for (int j = i + 1; j < n; j++) {
                int need = target - nums[i] - nums[j];
                while (k > j && nums[k] >= need) {
                    k--;
                }
                if (k <= j)
                    break;
                ans += (k - j);
            }
        }
        return ans;
    }
};

/*
[-2,0,1,3]
2


*/
