/*
Link: https://leetcode.com/discuss/interview-question/937739/Google-or-Phone-or-Find-max-unhealthy-period
Solved by: emotionless

You have an array of error rates 10, 2, 3, 5, 1, 7, 4, 8 and position of the element pos = 5.
Find such subarray (could be the whole array) that contains element with specified position, where product of min(subarray) * length(subarray) is maximum. Return -1 in case of error.

For the given array the answer is 12 (subarray 7, 4, 8).

*/

#include <iostream>
#include <vector>

using namespace std;

class Unhealty {
public:

    int maxUnhealthyServerTime(vector<int> rates, int pos) {
        int i = pos, j = pos;
        int n = rates.size();
        int mn = rates[pos];
        int ans = 0;
        while (i >= 0 || j < n) {
            int l = 0, r = 0;
            if (i >= 0) l = rates[i];
            if (j < n) r = rates[j];
            if (l > r) {
                mn = min(mn, rates[i]);
                i--;
                while (i >= 0 && rates[i] >= mn) {
                    i--;
                }
            } else {
                mn = min(mn, rates[j]);
                j++;
                while (j < n && rates[j] >= mn) {
                    j++;
                }
            }
            ans = max(ans, (j-i-1) * mn);
        }
        return ans;
    }
};


int main() {
    Unhealty unhealty = Unhealty();
    cout << unhealty.maxUnhealthyServerTime({10, 2, 3, 5, 1, 7, 4, 8}, 5) << endl;
    return 0;
}

/*

Time complexity: O(n)
Space complexity: O(h), h = height of the tree

*/
