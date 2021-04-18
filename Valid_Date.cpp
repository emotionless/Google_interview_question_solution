/*
Link: https://leetcode.com/discuss/interview-question/700536/Google-or-Phone-or-Valid-Date

Given 3 integers, check whether a valid date can be formed or not.
The input does not have a specific format.

Example 1:

Input: [2000, 10, 10]
Output: true
Example 2:

Input: [1, 32, 1990]
Output: false
Example 3:

Input: [2, 2000, 30]
Output: false
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int longestSuarrayMidpoint(vector<int> vec) {
        sort(vec.begin(), vec.end());
        do {
            if (isValid(vec[0], vec[1], vec[2]))
                return true;
        } while(next_permutation(vec.begin(), vec.end()));
        return false;
    }

private:

    bool isLeapYear(int year) {
        if (year %4 == 0) {
            if (year % 100 == 0) {
                return year % 400 == 0;
            }
            return true;
        }
        return false;
    }

    bool isValid(int day, int month, int year) {
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1)
            return false;
        int totalDays = days[month];
        if (month == 2 && isLeapYear(year)) {
            totalDays++;
        }
        return day <= totalDays;
    }
};


int main() {
    Solution sl = Solution();
    cout << sl.longestSuarrayMidpoint({2, 2000, 30}) << endl;
    cout << sl.longestSuarrayMidpoint({29, 2001, 2}) << endl;
    cout << sl.longestSuarrayMidpoint({1, 1, 30010}) << endl;
    cout << sl.longestSuarrayMidpoint({1, 2000, 10}) << endl;
    return 0;
}
