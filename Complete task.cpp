/*
Link: https://leetcode.com/discuss/interview-question/967367/Google-or-on-site-or-find-array-of-integer-is-fit-to-the-other

Given two arrays a,b with positive integers
the item i in a represents a server which hasa[i] cores.
the item iin b represents a tasks that needs b[i] cores in order to be execute.
single server can run multiple tasks but single task can only be execte in single server.

return true if servers can run the tasks and false otherwise.

examples:

a = [2,4] b = [1,1,4]
1,1->2
4-> 4
result = true
a = [1,3] b = [2,2]
result = false
a = [8,10] b = [2,3,3,3,7]
2,3,3->8
3,7 -> 10
result = true
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
const int INF = 1000000;

bool solve(int ind, vector<int> &cores, const vector<int> &need) {
    if (ind == need.size()) {
        return true;
    }
    for (int i = 0; i < cores.size(); i++) {
        if (need[ind] <= cores[i]) {
             cores[i] -= need[ind];
             if (solve(ind + 1, cores, need)) {
                return true;
             }
             cores[i] += need[ind];
        }
    }
    return false;
}

bool possible(vector<int> cores, const vector<int> need) {
    return solve(0, cores, need);
}

int main() {

    cout << possible({2, 4}, {1, 1, 4}) << endl;
    cout << possible({1, 3}, {2, 2}) << endl;
    cout << possible({8, 10}, {2, 3, 3, 3, 7}) << endl;

    return 0;
}
