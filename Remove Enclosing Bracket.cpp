/*
Link: https://leetcode.com/discuss/interview-question/889130/Google-or-Phone-or-Remove-Enclosing-Bracket

Given s String with some characters and brackets. Return String after removing Enclosing Brackets. Also provide a set of test cases for the problem
For Example:
(((a))) -> a
((ab)(bc))d -> ((ab)(bc))d
() => ""
((a)(bcd)(e)) -> (a)(bcd)(e)

*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeEnclosingBracket(string str) {
        int l = str.length();
        int ans = 0;
        while(ans < l && str[ans] == '(' && str[l-ans-1] == ')') {
            ans++;
        }
        int avail = 0;
        for (int i = ans; i < (l - ans); i++) {
            if (str[i] == '(') avail++;
            else if (str[i] == ')') {
                if (avail == 0) ans--;
                else avail--;
            }
        }
        return str.substr(ans, l - 2*ans);
    }
};

int main() {
    Solution sn = Solution();
    cout << sn.removeEnclosingBracket("((a)(bcd)(e))") << endl;
    cout << sn.removeEnclosingBracket("(((a)))") << endl;
    cout << sn.removeEnclosingBracket("((ab)(bc))d") << endl;

    return 0;
}
