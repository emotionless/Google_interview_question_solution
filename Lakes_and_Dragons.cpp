/*
Link:  https://leetcode.com/discuss/interview-question/629293/Google-or-Phone-or-Lakes-and-Dragons

I've encountered this question in a 45 minutes phone interview with Google for new grad position.
Given n lakes numbered from 1 to n and given m days of the weather report.
There is a dragon that can drain a lake but this dragon cannot appear on a rainy day.
You will be given an array weather of size m (0 <= weather[i] <= n) where weather[i] is the ID of the lake where it will rain in the ith day, or weather[i] = 0 which indicates a sunny day (dragon can appear).
Initially, all lakes are empty. When it rains in someday over some lake, this lake becomes full of water. If it rained twice over the same lake, there will be a flood in this lake. If someday it didn't rain (i.e. weather[i] = 0) the dragon will appear and you can ask the dragon to empty one lake (dragon will do nothing if the lake already empty).

You should find for each time a dragon apears, the lake it will be assigned to, in order to avoid floods.
If it is impossible to avoid floods return any default value.

Examples:

Input: 3, 4, [1,0,2,0]
Output: [1,2]
Explanation: After the first day, lake 1 is full of water.
The second day a dragon will appear you can assign him to any lake now.
The third day it rains over lake 2 and it's now full of water.
The fourth day the dragon appears and you can assign him to any lake.
In this example there will be no flood and you can assign the dragon each time to any lake.
([1,1], [1,2], [1,3], [2,1], [2,2] and [2,3] are all valid answers).
Input: 3, 4, [1,1,0,0]
Output: cannot stop flood
Explanation: After the first day, lake 1 is full of water. The second day it will rain again over lake 1 and it will flood.
Seems there is no way to avoid flood and in this case interviewer asked me to define a default value and return it.
Since the IDs of the lake take value from 1 to n I chose to return (n + 1)
Return value in my code was [4,4]
Input: 3, 7, [1,2,0,2,3,0,1]
Output: [2,1] (only valid answer)
Explanation: The first time the dragon appears, it must drain lake 2 so that next time it will not flood.
The second time the dragon appears, it must drain lake 1 because it will rain over lake 1 and lake 1 is already full.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> canAvoidFlood(int n, int m, vector<int> weather) {
        int i = 0, j = 0;
        unordered_map<int, int> counter;
        vector<int> ans;
        while (i < m) {
            if (weather[i] == 0) {
                j = max(j, i + 1);
                while (j < m) {
                    if (weather[j] > 0) {
                        int cnter = counter[ weather[j] ];
                        if (cnter == 1) {
                            counter[ weather[j] ]--;
                            ans.push_back(weather[j]);
                            break;
                        }
                    }
                    j++;
                }
                if (j >= m) {
                    ans.push_back(1);
                }
            } else {
                counter[ weather[i] ]++;
                if (counter[weather[i]] > 1) {
                    return {};
                }
            }
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol = Solution();
    auto ans = sol.canAvoidFlood( 3, 4, {1,0,2,0});
    for (auto v : ans) {
        cout << v << " ";
    }
    cout << endl;
    auto ans1 = sol.canAvoidFlood(3, 7, {1,2,0,2,3,0,1});
    for (auto v : ans1) {
        cout << v << " ";
    }

    cout << endl;


}
