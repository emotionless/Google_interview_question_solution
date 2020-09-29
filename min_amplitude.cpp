#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minAmplitude(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n <= 4) return 0;
    int j = n - 4;
    int ans = INT_MAX;
    for(int i = 0; i < 3; i++) {
        ans = min(ans, nums[j] - nums[i]);
        j++;
    }
    return ans;
}

int main() {
    vector<int> nums({10, 10, 3, 4, 10});
    cout << minAmplitude(nums) << endl;

    return 0;
}
