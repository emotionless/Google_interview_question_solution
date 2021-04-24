/*
Link: https://leetcode.com/discuss/interview-question/879774/Google-or-Onsite-or-Binary-Searchable-Elements


Binary search is a search algorithm usually used on a sorted sequence to quickly find an element with a given value. In this problem we will evaluate how binary search performs on data that isn't necessarily sorted. An element is said to be binary searchable if an element can be found provided the pivot is chosen everytime as the middle element - like in a regular binary search.
We need to find total number of elements which are binary searchable.

Example 1:

[2, 1, 3, 4, 6, 5] - 3 is searchable, 2 is searchable, 1 not searchable, 6 is searchable, 4 is seachable, 5 is not searchable
Output: 4
Example 2:

Input: [1, 3, 2]
Output: 2
Explanation: 3 and 1 are searchable - you look for 3 - find it in the middle, look for 1 - you search the left half....search for 2, you look for it in the left half but didn't find.
*/
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

class Solution {
public:
    int getSearchableCount(vector<int> nums) {
        int n = nums.size();
        return binarySearch(0, n - 1, INT_MIN, INT_MAX, nums);
    }
private:
    int binarySearch(int st, int ed, int mn, int mx, const vector<int> &nums) {
        if (st > ed)
            return 0;
        int mid = (st + ed) / 2;
        int ret = 0;
        if (mn <= nums[mid] && nums[mid] <= mx)
            ret++;
        return ret + binarySearch(st, mid - 1, mn, min(mx, nums[mid]), nums)
               + binarySearch(mid + 1, ed, max(mn, nums[mid]), mx, nums);
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.getSearchableCount({2, 1, 3, 4, 6, 5}) << endl;
    cout << sol.getSearchableCount({1, 3, 2}) << endl;

    return 0;
}
