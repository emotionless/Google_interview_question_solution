/*
Link:  https://leetcode.com/discuss/interview-question/653576/Google-or-Phone-or-Common-substrings-between-two-strings

Given two large articles, please search and return for all the sub-sentences which existing in both articles. The sub-sentence is required at least more than three words.

Example 1:

Input: a = "today is sunny and okay I feel yes so happy", b = "tomorrow is sunny and that makes today is sunny and okay me feel yes so happy too"
Output: ["is sunny and", "feel yes so happy", "today is sunny and okay"]

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> commonSubstrings(string a, string b) {
        vector<vector<int>> dp;
        vector<string> arr1 = split(a);
        vector<string> arr2 = split(b);
        int n = arr1.size();
        int m = arr2.size();
        dp.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr1[i] == arr2[j]) {
                    dp[i][j] = ((i && j)? dp[i-1][j-1] : 0) + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        vector<string> ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] >= 3 && ((i+1) >= n || (j+1) >= m || dp[i+1][j+1] == 0)) {
                    string str = "";
                    int r = i, c = j;
                    while (r >= 0 && c >=0 && dp[r][c] > 0) {
                        str = arr1[r] + " " + str;
                        r--;
                        c--;
                    }
                    str.pop_back();
                    ret.push_back(str);
                }
            }
        }
        return ret;
    }
private:
    vector<string> split(string str) {
        stringstream ss(str);
        vector<string> ret;
        string tmp;
        while (ss >> tmp) {
            ret.push_back(tmp);
        }
        return ret;
    }
};

int main() {
    Solution sol = Solution();
    string a = "today is sunny and okay I feel yes so happy";
    string b = "tomorrow is sunny and that makes today is sunny and okay me feel yes so happy too";
    auto ans = sol.commonSubstrings(a, b);
    for (auto ele : ans) {
        cout << ele << endl;
    }
    return 0;
}
