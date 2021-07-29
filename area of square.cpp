/*
Link: https://leetcode.com/discuss/interview-question/882062/Google-or-Onsite-or-Phone-Interviews  and Q4

Given a matrix with only 1s and 0s with exactly one square in the matrix,
find
1) the top left coordinate of square
2) area of square

Example:
[[0, 0, 0, 0, 0],
[0, 0, 1, 1, 0],
[0, 0, 1, 1, 0],
[0, 0, 0, 0, 0]]

The output will be (2,1) and 4.

*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;
int dr[4] = {-1, -1, 1, 1};
int dc[4] = {-1, 1, 1, -1};

const int n = 8;
const int INF = 100000000;

tuple<int, int, int> findSquare(const vector<vector<int>> mat) {
    int n = mat.size();
    if (n == 0)
        return make_tuple(-1, -1, -1);
    int m = mat[0].size();
    if (m == 0)
        return make_tuple(-1, -1, -1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                int cnt = 0;
                for (int k = 1; (i+k) < n && (j+k) < m; k++) {
                    cnt++;
                    if (mat[i+k][j+k] == 0) {
                        return make_tuple(i, j, k*k);
                    }
                }
                return make_tuple(i, j, cnt*cnt);
            }
        }
    }
    return make_tuple(-1, -1, -1);
}

int main() {
    vector<vector<int>> mat {{0, 0, 0, 0, 0},{0, 0, 1, 1, 0},{0, 0, 1, 1, 0},{0, 0, 0, 0, 0}};
    auto ans = findSquare(mat);
    cout << get<0> (ans) << " " << get<1>(ans) << " " << get<2>(ans) << endl;

    return 0;
}
