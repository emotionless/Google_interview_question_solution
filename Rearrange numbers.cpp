/*
Link: https://www.quora.com/Given-a-zero-indexed-array-A-1-2-3-n-of-n-integers-how-can-we-re-arrange-the-numbers-in-it-such-that-for-any-two-numbers-a-i-and-a-j-i-j-their-average-does-not-lie-between-i-and-j

Given a zero-indexed array 'A'= {1, 2, 3, ..., n} of 'n' integers,
how can we re-arrange the numbers in it such that for any two numbers a [i] and a [j] (i < j), their average does not lie between a[i] and a[j]?
*/
#include <iostream>
#include <vector>

using namespace std;


vector<int> rearrangeNumbers(vector<int> nums) {
    int n = nums.size();
    if (n <= 1) return nums;
    vector<int> left, right;
    for (int i = 0; i < n; i +=2) {
        left.push_back(nums[i]);
        if((i+1) < n) {
            right.push_back(nums[i+1]);
        }
    }
    auto l = rearrangeNumbers(left);
    auto r = rearrangeNumbers(right);
    for (auto v : r) {
        l.push_back(v);
    }
    return l;
}


int main() {
    vector<int> nums{1,2,3,4,5,6,7,8,9};
    auto ans = rearrangeNumbers(nums);
    for (auto v : ans) {
        cout << v << " ";
    }

    return 0;
}
