/*
link: https://leetcode.com/discuss/interview-question/922076/Google-or-Phone-(London)-or-Maximize-sum-with-multiplier-array
*/

#include <iostream>
#include <vector>

using namespace std;

class MaxSum {
public:
    MaxSum() {

    }

    int getMaxSumWithMultiplier(vector<int> A, vector<int> B) {
        int n = A.size();
        dp.clear();
        dp.resize(n, vector<int>(n, -1));
        return solve(0, n-1, 0, A, B);
    }

private:
    vector<vector<int>> dp;

    int solve(int i, int j, int k, const vector<int> &A, const vector<int> &B) {
        if (k == B.size()) {
            return 0;
        }
        if (i > j) {
            return 0;
        }
        int &ret = dp[i][j];
        if (ret != -1) return ret;
        ret = 0;
        ret = A[i] * B[k] + solve(i+1, j, k+1, A, B);
        ret = max(ret, A[j] * B[k] + solve(i, j-1, k+1, A, B));

        return ret;
    }

};


int main() {
    MaxSum ms = MaxSum();
    cout << ms.getMaxSumWithMultiplier({2, 13, 7, 15}, {2, 3}) << endl;
    cout << ms.getMaxSumWithMultiplier({-2,8,1,15,-6}, {3, 2, 5}) << endl;

    return 0;
}
