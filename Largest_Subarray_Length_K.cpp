#include <iostream>
#include <vector>

using namespace std;

bool isLarger(const vector<int> nums, int i, int j, int k) {
    for(int ind = 0; ind < k; ind++) {
        if (nums[i+ind] > nums[j+ind]) return true;
        else if (nums[i+ind] < nums[j+ind]) return false;
    }
    return true;
}

vector<int> largestSubarrayLengthK(const vector<int> nums, int k) {
    int ind = 0;
    int n = nums.size();
    for(int i = 0; i <= (n-k); i++) {
        if (isLarger(nums, i, ind, k)) {
            ind = i;
        }
    }
    return vector<int>(nums.begin() + ind, nums.begin() + ind + k);
}

int main() {
    vector<int> arr({1, 4, 3, 2, 5});
    vector<int> ans = largestSubarrayLengthK(arr, 4);
    for(auto v : ans) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
