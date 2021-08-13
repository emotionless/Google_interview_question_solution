/*
Problem link: https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

Given an m x n matrix mat where every row is sorted in strictly increasing order, return the smallest common element in all rows.

If there is no common element, return -1.



Example 1:

Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5
Example 2:

Input: mat = [[1,2,3],[2,3,4],[2,3,5]]
Output: 2


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 104
mat[i] is sorted in strictly increasing order.
*/


// solved by Milon

class Solution {
public:
    struct comparator {
        bool operator()(const vector<int>::iterator &a, const vector<int>::iterator &b) {
            return -(*a) < -(*b);
        }
    };

    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size();
        priority_queue<vector<int>::iterator, vector<vector<int>::iterator>, comparator> pq;
        int mx = 0;
        set<vector<int>::iterator> endList;
        for (auto &v : mat) {
            pq.push(v.begin());
            mx = max(mx, *(v.begin()));
            endList.insert(v.end());
        }
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if (*it == mx) {
                return mx;
            }
            it++;
            if (endList.find(it) != endList.end()) {
                break;
            }
            mx = max(*it, mx);
            pq.push(it);
        }
        return -1;
    }
};
