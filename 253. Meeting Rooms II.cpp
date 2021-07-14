/*
Link:  https://leetcode.com/problems/meeting-rooms-ii/

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.



Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1


Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106
*/

// solved by Milon
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        unordered_map<int, int> counter;
        set<int> nums;
        for (auto interval : intervals) {
            counter[interval[0]]++;
            counter[interval[1]]--;
            nums.insert(interval[0]);
            nums.insert(interval[1]);
        }
        int cnt = 0;
        int mx = 0;
        for (auto v : nums) {
            cnt += counter[v];
            mx = max(mx, cnt);
        }
        return mx;
    }
};
