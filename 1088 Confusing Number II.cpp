/*
Problem link: https://leetcode.com/problems/confusing-number-ii/

We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid.

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.(Note that the rotated number can be greater than the original number.)

Given a positive integer N, return the number of confusing numbers between 1 and N inclusive.



Example 1:

Input: 20
Output: 6
Explanation:
The confusing numbers are [6,9,10,16,18,19].
6 converts to 9.
9 converts to 6.
10 converts to 01 which is just 1.
16 converts to 91.
18 converts to 81.
19 converts to 61.
Example 2:

Input: 100
Output: 19
Explanation:
The confusing numbers are [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100].


Note:

1 <= N <= 10^9

*/

// solved by Milon

class Solution {
public:
    int oposite[100];
    bool isConfusing(long long num) {
        string str = to_string(num);
        int ind = 0;
        while(num) {
            int d = num % 10;
            if (oposite[d] != (str[ind]-'0')) return true;
            ind++;
            num /= 10;
        }

        return false;
    }

    int solve(long long n) {
        if (n > _n) return 0;
        int ret = isConfusing(n);
        // cout << n << " " << ret << endl;
        if (n)
            ret += solve(n * 10 + 0);
        ret += solve(n * 10 + 1);
        ret += solve(n * 10 + 6);
        ret += solve(n * 10 + 8);
        ret += solve(n * 10 + 9);

        return ret;
    }

    int confusingNumberII(int N) {
        _n = N;
        oposite[0] = 0;
        oposite[1] = 1;
        oposite[6] = 9;
        oposite[8] = 8;
        oposite[9] = 6;

        return solve(0);
    }
private:
    int _n;
};
