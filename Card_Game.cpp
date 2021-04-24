/*
Link: https://leetcode.com/discuss/interview-question/537699/

Two players are playing a card game where the deck of cards are layed out in a straight line and each card value is visible to both the players.
The value of each card can range from a reasonable [-ve to +ve] number and the length of deck in n.

The rules of the game are such:

Player 1 starts the game
Each player has 3 option:
(Option 1: Pick 1st card)
(Option 2: Pick 1st two cards)
(Option 3: Pick 1st three cards)
You're only allowed to pick cards from the left side of the deck
Both players have to play optimally.
Return the maximum sum of cards Player 1 can obtain by playing optimally.

Example 1:

Input: cards = [1, 2, -3, 8]
Output: 3
Explanation:
Turn 1: Player 1 picks the first 2 cards: 1 + 2 = 3 points
Turn 2: Player 2 gets the rest of the deck: -3 + 8 = 5 points
Example 2:

Input: cards = [1, 1, 1, 1, 100]
Output: 101
Explanation:
Turn 1: Player 1 picks cards[0] = 1 point
Turn 2: Player 2 picks cards[1] + cards[2] + cards[3] = 3 points
Turn 3: Player 1 picks cards[4] = 100 points

*/
#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

class Solution {
public:
    int maxScore(vector<int> nums) {
        int n = nums.size();
        dp.clear();
        dp.resize(n, vector<int> (2, -1));
        int sum = solve(0, true, nums);
//        return sum;
        int mem[5][2];
        memset(mem, 0, sizeof mem);
        for (int i = n - 1; i >= 0; i--) {
            int sum = nums[i];
            mem[i%4][1] = sum;
            mem[i%4][0] = INT_MAX;
            for (int j = i + 1; j <= (i + 3) && j <= n; j++) {
                if (j < n) {
                    mem[i%4][1] = max(sum + mem[j%4][0], mem[i%4][1]);
                    mem[i%4][0] = min(mem[j%4][1], mem[i%4][0]);
                    sum += nums[j];
                } else {
                    mem[i%4][1] = max(sum, mem[i%4][1]);
                    mem[i%4][0] = min(0, mem[i%4][0]);
                }
            }
            if (mem[i%4][0] == INT_MAX)
                mem[i%4][0] = 0;
            // cout << i % 4 << " " << 0 << " " << mem[i%4][0] << endl;
            // cout << i % 4 << " " << 1 << " " << mem[i%4][1] << endl;
        }
        return mem[0][1];
    }
private:
    vector< vector<int> > dp;

    int solve(int ind, bool is, const vector<int> &nums) {
        if (ind >= nums.size()) {
            return 0;
        }
        int &ret = dp[ind][is];
        if (ret != -1)
            return ret;
        ret = 0;
        if (is) {
            int sum = nums[ind];
            ret = sum;
            for (int i = ind + 1; i <= (ind + 3); i++) {
                ret = max(ret, sum + solve(i, false, nums));
                if (i >= nums.size())
                    break;
                sum += nums[i];
            }
        } else {
            ret = 0;
            for (int i = ind + 1; i <= (ind + 3); i++) {
                ret = min(ret, solve(i, true, nums));
                if (i >= nums.size())
                    break;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.maxScore({1, 2, -3, 8}) << endl;
    cout << sol.maxScore({1, 1, 1, 1, 100}) << endl;


    return 0;
}
