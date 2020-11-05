/*
Problem link: https://leetcode.com/discuss/interview-question/921482/Jaguar-Land-Rover-or-OA-or-On-Campus-or-2020
Solution Author: emotionless
Date: 05 Nov 2020

*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>


using namespace std;

// time O(n), space: O(n)
int minNumberOfDayss(const vector<int> &nums) {

    int n = nums.size();
    stack<int> container;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        while(container.size() > 0 && nums[i] <= nums[container.top()]) {
            container.pop();
        }
        if (container.size() > 0) {
            ans = max(ans, i - container.top());
        }
        container.push(i);
    }
    return ans;
}


// Time: O(n), space: O(1)
int minNumberOfDays(const vector<int> &nums) {

    int n = nums.size();
    int ans = 0;
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if (nums[i] <= nums[i-1]) {
            cnt++;
        } else {
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    return ans;
}

int main()
{
    vector<int> arr({6, 5 , 8, 4, 7 ,10, 9});

    cout << minNumberOfDayss(arr) << endl;
    cout << minNumberOfDays(arr) << endl;

    return 0;
}

/*

Time complexity:
O(n)
Space complexity:
O(1)

*/
