/*
Link: https://leetcode.com/discuss/interview-question/917409/Google-or-Phone-or-Longest-Subarray-Sum-at-Most-K

find the longest subarray whose sum is less or equal to K

int[] arr = {1, 2, 1, 0, 1, -8, -9, 0};
int k = 4;
Output is 8

int arr[] = {1, 2, 1, 0, 1, 1, 0};
int k = 4;
output is 5

*/

#include <iostream>
#include <vector>

using namespace std;

class SubArray {
public:
    int getLongestSubArraySum(vector<int> arr, int k) {
        int n = arr.size();
        preSum.clear();
        preSum.resize(n, 0);
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum <= k) {
                ans = i + 1;
            } else {
                int j = i - ans - 1;
                while (j >= 0 && preSum[j] >= (sum - k)) {
                    ans++;
                    j--;
                }
            }
            if (i == 0) {
                preSum[i] = sum;
            } else {
                preSum[i] = max(preSum[i-1], sum);
            }
        }
        return ans;
    }

private:
    vector<int> preSum;
};

int main() {
    SubArray sa = SubArray();
    cout << sa.getLongestSubArraySum({1, 2, 1, 0, 1, -8, -9, 0}, 4) << endl;
    cout << sa.getLongestSubArraySum({1, 2, 1, 0, 1, 1, 0}, 4) << endl;

    return 0;
}
