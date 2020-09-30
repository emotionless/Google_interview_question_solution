#include <iostream>
#include <vector>

using namespace std;

class MinAbsDiff {
public:
    MinAbsDiff() {
        dp.clear();
    }

    int minAbsDiff(vector<int> nums) {
        int n = nums.size();
        if (n == 0) return 0;
        dp.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            dp[i].clear();
        }
        int s = 0;
        for(auto v : nums) {
            s += v;
        }
        int m = s / 2;
        for(int i = 0; i <= n; i++) {
            dp[i].resize(m + 1);
            dp[i][0] = 1;
        }
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = nums[i]; j <= m; j++) {
                dp[i+1][j] = dp[i+1][j] | dp[i][j - nums[i]];
                if (dp[i+1][j]) {
                    //cout << j << endl;
                    mx = max(mx, j);
                }
            }
        }
        return abs((s - mx) - mx);
    }
private:
    vector<vector<bool>> dp;
};

int main() {
    MinAbsDiff mad = MinAbsDiff ();
    vector<int> input({1, 2, 3, 4, 5});
    cout << mad.minAbsDiff(input) << endl;
    vector<int> input1({10,10,9,9,2});
    cout << mad.minAbsDiff(input1) << endl;


    return 0;
}
