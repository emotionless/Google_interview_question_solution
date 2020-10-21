#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <climits>


using namespace std;

class CutTheCake {
public:

    int getNumberOfWays(vector<vector<int>> cake, int k) {
        int r = cake.size();
        if (r == 0) return 0;
        int c = cake[0].size();
        memset(dp, -1, sizeof dp);
        csum.clear();
        csum.resize(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if (i == 0 && j == 0) csum[i][j] = cake[i][j];
                else if(i == 0) csum[i][j] = cake[i][j] + csum[i][j-1];
                else if(j == 0) csum[i][j] = cake[i][j] + csum[i-1][j];
                else csum[i][j] = cake[i][j] + csum[i-1][j] + csum[i][j-1] - csum[i-1][j-1];
            }
        }
        return numberOfWays(0, 0, r, c, k);
    }

private:
    vector<vector<int>> csum;
    int dp[10][10][10];

    bool strawberryExist(const int x1, const int y1, const int x2, const int y2) {
        int sum = csum[x2][y2] - (y1 > 0?csum[x2][y1-1]:0) - (x1>0?csum[x1-1][y2]:0) + ((x1&&y1)?csum[x1-1][y1-1]:0);
        return sum > 0;
    }

    int numberOfWays(const int i, const int j, const int r, const int c, const int rem) {
        if (i == r || j == c) return 0;
        if (rem == 1) {
            return strawberryExist(i, j, r - 1, c - 1);
        }

        int &ret = dp[i][j][rem];
        if (ret != -1) return ret;
        ret = 0;

        // vertically cut
        for(int k = j; k < c; k++) {
            if (strawberryExist(i, j, r - 1, k))
                ret += numberOfWays(i, k + 1, r, c, rem - 1);
        }

        // horizontal cut
        for(int k = i; k < r; k++) {
            if (strawberryExist(i, j, k, c - 1))
                ret += numberOfWays(k+1, j, r, c, rem - 1);
        }

        return ret;
    }

};
int main()
{
    vector<vector<int>> cake0({{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}});
    vector<vector<int>> cake1({{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}});
    vector<vector<int>> cake2({
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                              });

    CutTheCake ctc;

    cout << ctc.getNumberOfWays(cake0, 2) << endl;
    cout << ctc.getNumberOfWays(cake1, 5) << endl;
    cout << ctc.getNumberOfWays(cake2, 5) << endl;

    return 0;
}

/*

Time complexity:
O(r*c*friends*max(r, c))
Space complexity:
O(r*c*friends)

*/
