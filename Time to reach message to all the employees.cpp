/*
Link: https://leetcode.com/discuss/interview-question/707842/Google-or-Phone-or-Time-to-reach-message-to-all-the-employees

There is a company consisting of N people, each with a manager who may have one or more other reports.

At the top of the company’s hierarchy is the CEO, who emails a message to all of his reports, asking them to forward the message to all of their reports.

Assuming every manager takes their own characteristic amount of time to forward the message to their reports, how long does it take for the message to get to everyone in the company?

Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.

Input: n = 15, headID = 0, manager = [-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6], informTime = [1,1,1,1,1,1,1,0,0,0,0,0,0,0,0]
Output: 3

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> manager, vector<int> informTime) {
        adjn.clear();
        adjn.resize(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adjn[manager[i]].push_back(i);
            }
        }
        return getInformTime(headID, informTime);
    }

private:
    vector<vector<int>> adjn;

    int getInformTime(int cur, const vector<int> &informTime) {
        int ret = 0;
        for (auto v : adjn[cur]) {
            ret = max(ret, informTime[cur] + getInformTime(v, informTime));
        }
        return ret;
    }
};


int main() {
    Solution sl = Solution();
    cout << sl.numOfMinutes(7, 6, {1,2,3,4,5,6,-1}, {0,6,5,4,3,2,1}) << endl;
    cout << sl.numOfMinutes(15, 0, {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6}, {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0}) << endl;


    return 0;
}
