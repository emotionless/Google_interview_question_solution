/*
Link:  https://leetcode.com/discuss/interview-question/823513/Google-or-Onsite-or-Good-Subarray

given an n x m matrix and a value k, find minimum values for all sub-matrixes of size k

example:
given this matrix:

	[
        [-1, 5, 4, 1, -3],
        [4,  3, 1, 1, 6],
        [2, -2, 5, 3, 1],
        [8,  5, 1, 9, -4],
        [12, 3, 5, 8, 1]
    ]
and a k of 3

result:

[
	[-2, -2, -3],
	[-2, -2, -4],
	[-2, -2, -4]
]

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMinimumValues(vector<vector<int>> matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> grid(n - k + 1, vector<int> (m));
        for (int j = 0; j < m; j++) {
            deque<pair<int, int>> dq;
            for (int i = 0; i < n; i++) {
                while (!dq.empty()) {
                    if (dq.back().second > matrix[i][j]) {
                        dq.pop_back();
                    } else {
                        break;
                    }
                }
                dq.push_back({i, matrix[i][j]});
                while (dq.front().first <= (i - k))
                    dq.pop_front();
                if (i >= (k-1))
                    grid[i-k+1][j] = dq.front().second;
            }
        }
        vector<vector<int>> ans(n - k + 1, vector<int> (m - k + 1));
        for (int j = 0; j < grid.size(); j++) {
            deque<pair<int, int>> dq;
            for (int i = 0; i < grid[j].size(); i++) {
                while (!dq.empty()) {
                    if (dq.back().second > grid[j][i]) {
                        dq.pop_back();
                    } else {
                        break;
                    }
                }
                dq.push_back({i, grid[j][i]});
                while (dq.front().first <= (i - k))
                    dq.pop_front();
                if (i >= (k-1))
                    ans[j][i-k+1] = dq.front().second;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol = Solution();

    auto ans = sol.findMinimumValues({
        {-1, 5, 4, 1, -3},
        {4,  3, 1, 1, 6},
        {2, -2, 5, 3, 1},
        {8,  5, 1, 9, -4},
        {12, 3, 5, 8, 1}
    }, 3);

    for (auto x : ans) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Average: O(n*m)
Worst case: O(n*m)
*/
