/*
Link:  https://leetcode.com/discuss/interview-question/627483/Facebook-or-Phone-or-Find-the-Quarter-Majority

Given a sorted array of size n, find the majority element. The majority element is the element that appears more than n/4 times. You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [1, 1, 2, 2, 3, 3, 3, 4, 5, 6, 7]
Output: 3
Example 2:

Input: [1, 1, 2, 2, 3, 3, 4, 5, 7, 7, 7]
Output: 7
Example 3:

Input: [1, 1, 2, 3]
Output: 1
Initialy, I've offer 2 solution

Use Map with key and count pair and go through the Map and return the true, if any of the count >= 1/4*length;
Use for loop with two pointer(first, prev) , increase the count, if values are same and return true when you see the count >=1/4* length;
Both the solutions are O(N) time complexity. But, she was expecting the O(log n) solution and she given below HINT:
int windowSize = arr.length*(1/4)
a[0] == a[0+windowSize-1]
a[0] != a[0+windowSize-1]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findQuarterMajority(vector<int> arr) {
        int n = arr.size();
        int len = (n / 4) + 1;
        vector<int> candidates;
        candidates.push_back(arr[0]);
        candidates.push_back(arr[n/4]);
        candidates.push_back(arr[(2*n)/4]);
        candidates.push_back(arr[(3*n)/4]);
        for (auto v : candidates) {
            auto p = lower_bound(arr.begin(), arr.end(), v) - arr.begin();
            if ((p + len - 1) < n && arr[p+len-1] == v) {
                return v;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.findQuarterMajority({1, 1, 2, 2, 3, 3, 3, 4, 5, 6, 7}) << endl;
    cout << sol.findQuarterMajority({1, 1, 2, 2, 3, 3, 4, 5, 7, 7, 7}) << endl;
    cout << sol.findQuarterMajority({1, 1, 2, 3}) << endl;
    return 0;
}

