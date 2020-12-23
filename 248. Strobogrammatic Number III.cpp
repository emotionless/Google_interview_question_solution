/*
Problem link: https://leetcode.com/problems/strobogrammatic-number-iii/

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

Example:

Input: low = "50", high = "100"
Output: 3
Explanation: 69, 88, and 96 are three strobogrammatic numbers.
Note:
Because the range might be a large number, the low and high numbers are represented as string.

*/

// solved by Milon

class Solution {
public:

    vector<char> elements{'0', '1', '6', '8', '9'};
    vector<char> revElements{'0', '1', '9', '8', '6'};
    char rev[150];


    int solve(int ind, bool smallFromLeft, bool largeFromRight, const string &tar) {
        int ind2 = len - 1 - ind;
        if (ind > ind2) {
            if (smallFromLeft) return 1;
            if (!largeFromRight) return 1;
            return 0;
        }
        int &ret = dp[ind][smallFromLeft][largeFromRight];
        if (ret != -1) return ret;
        ret = 0;

        if (ind == ind2) {
            char mx = (smallFromLeft? '9' + 1 : tar[ind]);

            for(int i = 0; i < elements.size(); i++) {
                char ch = elements[i];
                if (ch == '0' && ind == 0) continue;
                if (ch <= mx && ch != '9' && ch != '6') {
                    ret += solve(ind + 1, ch < mx, largeFromRight, tar);
                }
            }
            return ret;
        }


        char mx = (smallFromLeft? '9' + 1 : tar[ind]);

        for(int i = 0; i < elements.size(); i++) {
            char ch = elements[i];
            if (ch == '0' && ind == 0) continue;
            if (ch <= mx) {
                ret += solve(ind + 1, ch < mx, largeFromRight | (revElements[i] > tar[ind2]), tar);
            }
        }
        // cout << ind << " " << smallFromLeft << " " << largeFromRight << " " << ret << endl;
        return ret;
    }

    string highest(int n) {
        string ret = "";
        while(n--) {
            ret += '9';
        }
        return ret;
    }

    string makeRev(string str) {
        string ret = "";
        int l = str.length();
        for(int i = l - 1; i >= 0; i--) {
            ret += rev[str[i]];
        }
        return ret;
    }

    int getFor(string str) {
        int l = str.length();

        dp.resize(len, vector<vector<int>>(2, vector<int>(2, -1)));
        for(int i = 0; i < len ;i++) {
            for(int j = 0; j < 2; j++) {
                dp[i][j].clear();
            }
            dp[i].clear();
        }
        dp.clear();
        len = str.length();
        dp.resize(len, vector<vector<int>>(2, vector<int>(2, -1)));
        int ret = solve(0, 0, 0, str);
        string high;
        // cout << ret << endl;
        for(int i = 1; i < l; i++) {
            high = highest(i);
            len = i;

            for(int i = 0; i < len ;i++) {
                for(int j = 0; j < 2; j++) {
                    for(int k = 0; k < 2; k++) dp[i][j][k] = -1;
                }
            }
            int a = solve(0, 0, 0, high);
            // cout << len << " " << a << endl;
            ret += a;
        }
        return ret;
    }


    int strobogrammaticInRange(string low, string high) {
        rev['0'] = '0';
        rev['1'] = '1';
        rev['6'] = '9';
        rev['8'] = '8';
        rev['9'] = '6';
        len = high.length();
        int h = getFor(high);
        // cout << "For: " << high << " " << h << endl;
        int l = getFor(low);

        string rev = makeRev(low);
        if (low == rev) h++;


        return max(0, h - l);
    }
private:
    int len;
    vector<vector<vector<int>>> dp;
};
