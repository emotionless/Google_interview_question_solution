#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Solution {
public:

    Solution() {

    }

    char toUpper(char ch) {
        if (ch >= 'a' && ch <= 'z') ch = ch - 'a' + 'A';
        return ch;
    }

    string licenseKeyFormatting(string S, int K) {
        string ans;
        int n = S.length();
        int ind = n*2;
        ans.resize(ind);
        ind--;
        int rem = K;
        for(int i = S.length() - 1; i >= 0; i--) {
            if (S[i] == '-') continue;
            if (rem == 0) {
                ans[ind--] = '-';
                rem = K;
            }
            ans[ind--] = toupper(S[i]);
            rem--;
        }
        return ans.substr(ind+1);
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;

    return 0;
}
