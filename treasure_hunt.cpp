#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cassert>


using namespace std;

class TreasureHunt {
public:

    TreasureHunt(vector<vector<int>> mat) {
        this->mat.clear();
        for(auto v : mat) {
            this->mat.push_back(v);
        }
    }

    int getMaxTreasure() {
        n = mat.size();
        m = mat[0].size();
        dp.resize(n, vector<vector<int>> (m, vector<int>(m, -1)));
        if (n < 2) return -1;
        if (n == 1 && m == 1) return mat[0][0];
        return maxTreasure(0, 0, m-1);
    }



private:
    vector<vector<int>> mat;
    vector<vector<vector<int>>> dp;
    int n;
    int m;

    int maxTreasure(int r, int c1, int c2) {
        if (r == n-1 && c1 == 0 && c2 == m-1) return mat[r][c1] + mat[r][c2];
        if (r >= n || c1 < 0 || c1 >= m || c2 < 0 || c2 >= m || c1 > c2) return -100000000;
        if (r == n-1) return -100000000;

        int &ret = dp[r][c1][c2];
        if (ret != -1) return ret;
        ret = -100000000;
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                ret = max(ret, maxTreasure(r + 1, c1 + i, c2 + j));
            }
        }
        ret = mat[r][c1] + (c1 != c2?mat[r][c2]:0) + ret;
        return ret;
    }

};


int main()
{
    vector<vector<int>> mat(
                    {{9, 10, 15, 12, 11},
					{7, 5, 11, 6, 8},
					{4, 1, 27, 13, 17},
					{2, 4, 18, 2, 1},
					{15, 3, 22, 6, 10},
					{8, 2, 5, 9, 6}});
    TreasureHunt th = TreasureHunt(mat);

    cout << th.getMaxTreasure() << endl;

    vector<vector<int>> mat2(
                    {{3, 6, 8, 2},
					 {5, 2, 4, 3},
					 {1, 1, 20, 10},
					 {1, 1, 20, 10},
					 {1, 1, 20, 10}});
    TreasureHunt th2 = TreasureHunt(mat2);
    cout << th2.getMaxTreasure() << endl;


    return 0;
}

/*


Time complexity:
O(n*m*m)

Space complexity:
O(n*m*m)

*/
