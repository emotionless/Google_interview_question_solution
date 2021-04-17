/*
Link: https://leetcode.com/discuss/interview-question/883931/Google-or-Phone-or-Encode-String

Convert  aabczzzzabczzzzabczzzzc -> a(abcz(4))3c or a(abczzzz)3c
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string encodeString(string str) {
        int n = str.length();
        dp.clear();
        dp.resize(n, vector<string> (n));

        for (int step = 0; step < n; step++) {
            for (int i = 0; (i+step) < n; i++) {
                int j = i + step;
                dp[i][j] = str.substr(i, step + 1);
                for (int k = i; k < j; k++) {
                    string first = dp[i][k];
                    string last = dp[k+1][j];
                    if ((first + last).size() < dp[i][j].size()) {
                        dp[i][j] = first + last;
                    }
                }
                string encodedStr = encodeIntoSmall(str, i, j);
                if (encodedStr.size() < dp[i][j].size()) {
                    dp[i][j] = encodedStr;
                }
            }
        }
        return dp[0][n-1];
    }

private:
    vector<vector<string>> dp;

    string encodeIntoSmall(const string &str, int i, int j) {
        string tmp = str.substr(i, j - i + 1);
        size_t pos = (tmp + tmp).find(tmp, 1);
        if (pos >= tmp.size())
            return tmp;
        return "(" + dp[i][i + pos - 1] + ")" + to_string(tmp.size() / pos);
    }
};

int main() {
    Solution sn = Solution();
    cout << sn.encodeString("aabczzzzabczzzzabczzzzc") << endl;
    cout << sn.encodeString("azzzz") << endl;

    return 0;
}
