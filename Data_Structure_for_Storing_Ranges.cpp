/*
Link:  https://leetcode.com/discuss/interview-question/884712/Google-or-Phone-or-Data-Structure-for-Storing-Ranges

Design a data structure with two operations 1. addRange(int start, int end) and 2. isPresent(int point)
Here range means an interval, so the data structure contains information of all ranges added uptil that point. contains(int point) returns true if the point is contained in any of the ranges or false otherwise.

*/

#include <iostream>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:

    bool doesIntersect(pair<int, int> a, pair<int, int> b) {
        if (a.second < b.first || b.second < a.first)
            return false;
        return true;
    }

    void addRange(int st, int ed) {
        pair<int, int> cur = make_pair(st, ed);
        auto itSt = container.upper_bound(cur);
        if (itSt != container.begin())
            itSt--;
        int mn = st;
        int mx = ed;
        auto pre = container.end();
        for (auto it = itSt; it != container.end(); it++) {
            if ((*it).first > mx)
                break;
            if (doesIntersect(cur, *it)) {
                mn = min(mn, (*it).first);
                mx = max(mx, (*it).second);
            }
            pre = it;
        }
        if (pre != container.end())
            pre++;
        container.erase(itSt, pre);
        container.insert(make_pair(mn, mx));
    }

    bool isPresent(int point) {

        auto it = container.upper_bound(make_pair(point, INT_MAX));
        if (it == container.begin())
            return false;
        it--;
        if ((*it).first <= point && point <= (*it).second)
            return true;
        return false;
    }

private:
    set<pair<int, int>> container;

};

int main() {
    Solution sn = Solution();
    sn.addRange(10, 20);
    sn.addRange(15, 25);
    cout << sn.isPresent(9) << endl;
    cout << sn.isPresent(10) << endl;
    cout << sn.isPresent(21) << endl;
    sn.addRange(30, 32);
    cout << sn.isPresent(57) << endl;
    cout << sn.isPresent(29) << endl;
    cout << sn.isPresent(30) << endl;
    cout << sn.isPresent(32) << endl;
    cout << sn.isPresent(33) << endl;

    return 0;
}
