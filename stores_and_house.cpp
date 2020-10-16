#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>


using namespace std;


vector<int> closestLocation(vector<int> houses, vector<int> stores) {
    sort(stores.begin(), stores.end());
    for(auto &v : houses) {
        auto it = lower_bound(stores.begin(), stores.end(), v);
        if (it == stores.end()) {
            v = *(it-1);
            continue;
        } else if (it == stores.begin()) {
            v = *it;
            continue;
        }
        auto pre = it-1;
        if ((v - *(pre)) <= (*it - v)) {
            v = *(pre);
        } else {
            v = *it;
        }
    }
    return houses;
}

int main()
{
    vector<int> houses({5, 10, 17});
    vector<int> stores({1, 5, 20, 11, 16});

    auto ans = closestLocation(houses, stores);
    for(auto v : ans) {
        cout << v <<" ";
    }
    cout << endl;

    vector<int> houses1({2, 4, 2});
    vector<int> stores1({5, 1, 2, 3});

    ans = closestLocation(houses1, stores1);
    for(auto v : ans) {
        cout << v <<" ";
    }
    cout << endl;

    vector<int> houses2({4, 8, 1, 1});
    vector<int> stores2({5, 3, 1, 2, 6});

    ans = closestLocation(houses2, stores2);
    for(auto v : ans) {
        cout << v <<" ";
    }
    cout << endl;

    return 0;
}

/*

Time complexity:
O(sumOfLenths*26*log(n))
that is (sumOfLength * log(n)) where n = number of words, sumOfLength = sum of lengths of all words

Space complexity:
O(sumOfLength)

*/
