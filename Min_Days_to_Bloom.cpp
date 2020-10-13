#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;


int numberOfBouquets(const vector<int> roses, int k, int m) {
    int cnt = 0, tot = 0;
    for(auto v : roses) {
        if (v <= m) cnt++;
        else cnt = 0;
        if (cnt == k) {
            tot++;
            cnt = 0;
        }
    }
    return tot;
}

int minNumberOfBouquets(const vector<int> &roses, int k, int n) {
    int st = 0, ed = 0;
    for(auto v : roses) {
        ed = max(ed, v);
    }
    int ans = -1;
    while(st <= ed) {
        int m = (st + ed) / 2;
        if (numberOfBouquets(roses, k, m) >= n) {
            ans = m;
            ed = m - 1;
        } else {
            st = m + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> roses({1, 2, 4, 9, 3, 4, 1});
    cout << minNumberOfBouquets(roses, 2, 2) << endl;
    return 0;
}

/*

Time complexity:
O(nlog(n))
Space complexity:
O(1) [N.B: ignoring space for parameter of input (roses)]

*/
