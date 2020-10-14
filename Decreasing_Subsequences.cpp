#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>


using namespace std;

int decreasingSubsequences(const vector<int> &sequences) {
    int n = sequences.size();
    multiset<int> container;
    for(auto num : sequences) {
        auto it = container.upper_bound(num);
        if (it == container.end()) {
            container.insert(num);
        } else {
//            cout << num << " " << *it<<endl;
            container.erase(it);
            container.insert(num);
        }
    }
    return container.size();
}

int main()
{
    vector<int> arr({5, 2, 4, 3, 1, 6});
    cout << decreasingSubsequences(arr) << endl;
    cout << decreasingSubsequences({2, 9, 12, 13, 4, 7, 6, 5, 10}) << endl;
    cout << decreasingSubsequences({1, 1, 1}) << endl;


    return 0;
}

/*

Time complexity:
O(nlog(n))
Space complexity:
O(n)

*/
