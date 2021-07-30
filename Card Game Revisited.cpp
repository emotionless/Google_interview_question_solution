/*
Link: https://leetcode.com/discuss/interview-question/930843/Google-or-L3-or-Onsite

Card has 4 attributes (color, count, shading, shape), each attribute can have value 0, 1 or 2. 3 cards are considered as a set if for each attribute, 3 cards either have the same value or have different value from each other. For example:
card1 (2, 0, 1, 2), card2 (1, 0, 0, 1) and card3(0, 0, 2, 0) are 1 set.
card1(2, 0, 1, 2), card2 (1, 1, 0, 1) and card3(0, 1, 2, 0) are not 1 set.

write a boolean function with 3 cards as input. This function returns true if they are 1 set, otherwise returns false.
Now given a collection of cards, return true if there is a set of cards exsits, otherwise return false. The interviewer wants O(n^2) solution.

*/
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>


using namespace std;

int getMissingElement(int fstElmnt, int sndElmnt) {
    if (fstElmnt == sndElmnt) return fstElmnt;
    return 3 - fstElmnt - sndElmnt;
}

struct MyHash {
    int operator()(const vector<int> &a) const {
        return a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
    }
};

bool isSet(const vector<vector<int>> cards) {
    int n = cards.size();
    unordered_map<vector<int>, int, MyHash> counter;
    for (auto v : cards) {
        counter[v]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> arr;
            for (int k = 0; k < 4; k++) {
                arr.push_back(getMissingElement(cards[i][k], cards[j][k]));
            }
            if (counter.find(arr) != counter.end()) {
                counter[cards[i]]--;
                counter[cards[j]]--;
                if (counter[arr] > 0) {
                    return true;
                }
                counter[cards[i]]++;
                counter[cards[j]]++;
            }
        }
    }
    return false;
}

int main() {
    cout << isSet({{2, 0, 1, 2}, {1, 1, 0, 1}, {0, 1, 2, 0}}) << endl;
    cout << isSet({{2, 0, 1, 2}, {1, 0, 0, 1}, {0, 0, 2, 0}}) << endl;

    return 0;
}
