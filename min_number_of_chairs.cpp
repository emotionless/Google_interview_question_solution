#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;

int minNumberOfCharis(const vector<int> &arrival, const vector<int> &leave) {

    map<int, int> numOfPeoples;
    int n = arrival.size();
    for(int i = 0; i < n; i++) {
        numOfPeoples[ arrival[i] ]++;
        numOfPeoples[ leave[i] ]--;
    }
    int counter = 0;
    int mx = 0;
    for(auto it : numOfPeoples) {
        counter += it.second;
        mx = max(mx, counter);
    }
    return mx;
}

int main()
{
    vector<int> arr({1, 2, 6, 5, 3});
    vector<int> leave({5, 5, 7, 6, 8});

    cout << minNumberOfCharis(arr, leave) << endl;
    return 0;
}

/*

Time complexity:
O(nlog(n))
Space complexity:
O(n)

*/
