/*
Link: https://leetcode.com/discuss/interview-question/1357725/Google-Interview

Given array of ints find largest distance between two unique numbers

e.g e.g [1,2,4,1,5,2]

res = 5 which is dist from start to end
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;


int largestDistance(const vector<int> &arr) {
    int n = arr.size();
    int last1 = n - 1, last2 = n;
    int ind = n-2;
    while (ind >= 0 && arr[ind] == arr[ind + 1]) {
        ind--;
    }
    if (ind < 0) {
        return 0;
    }
    last2 = ind;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != arr[last1]) {
            mx = max(mx, last1 - i);
        } else {
            mx = max(mx, last2 - i);
        }
    }
    return mx;
}

int main() {
    vector<int> arr{1,2,4,1,5,2};
    vector<int> arr2{1,2,4,1,1,1};
    vector<int> arr3;

    cout << largestDistance(arr) << endl;
    cout << largestDistance(arr2) << endl;
    cout << largestDistance(arr3) << endl;

    return 0;
}
