/*
Problem link: https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

Given the availability time slots arrays slots1 and slots2 of two people and a meeting duration duration, return the earliest time slot that works for both of them and is of duration duration.

If there is no common time slot that satisfies the requirements, return an empty array.

The format of a time slot is an array of two elements [start, end] representing an inclusive time range from start to end.

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots [start1, end1] and [start2, end2] of the same person, either start1 > end2 or start2 > end1.



Example 1:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
Output: [60,68]
Example 2:

Input: slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
Output: []


Constraints:

1 <= slots1.length, slots2.length <= 104
slots1[i].length, slots2[i].length == 2
slots1[i][0] < slots1[i][1]
slots2[i][0] < slots2[i][1]
0 <= slots1[i][j], slots2[i][j] <= 109
1 <= duration <= 106
*/


// solved by Milon

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int j = 0, len1 = slots1.size(), len2 = slots2.size();
        int i = 0;
        while (i < len1 && j < len2) {
            int st = max(slots1[i][0], slots2[j][0]);
            int ed = min(slots1[i][1], slots2[j][1]);
            if ((ed - st) >= duration) {
                return {st, st + duration};
            } else {
                if (slots1[i][1] < slots2[j][1]) {
                    i++;
                } else {
                    j++;
                }
            }
        }

        return {};
    }
};

// solved by Milon

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        map<int, int> counter;
        for (auto v : slots1) {
            counter[v[0]]++;
            counter[v[1]]--;
        }
        for (auto v : slots2) {
            counter[v[0]]++;
            counter[v[1]]--;
        }
        int sum = 0;
        int st = -1;
        for (auto ele : counter) {
            sum += ele.second;
            if (sum == 2) {
                st = ele.first;
            } else {
                if (st != -1) {
                    if ((ele.first - st) >= duration) {
                        return {st, st + duration};
                    }
                }
                st = -1;
            }
        }
        return {};
    }
};
