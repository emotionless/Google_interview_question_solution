#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>


using namespace std;

class PizzaAndToppings {
public:

    bool needToDecrease(const int a, const int b) {
        mn = min(mn, remaining);
        mn = min(mn, abs(a - remaining));
        mn = min(mn, abs(b - remaining));
        mn = min(mn, abs(a + b - remaining));

        if ((a+b) >= remaining) return true;
        return false;
    }

    int groupStrings(const vector<int> pizzas, vector<int> toppings, const int x) {
        sort(toppings.begin(), toppings.end());
        for(auto cur : pizzas) {
            remaining = x - cur;
            if (remaining < 0) continue;

            for(int i = 0, j = toppings.size() - 1; i <= j; i++, j--) {
                if (needToDecrease(toppings[i], toppings[j])) {
                    j--;
                } else {
                    i++;
                }
            }
        }
        return mn;
    }



private:
    int remaining = 0;
    int mn = INT_MAX;
};
int main()
{
    vector<string> inp({"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"});

    vector<vector<string>> ans = groupStrings(inp);

    cout << (int)ans.size() << endl;

    for (auto element : ans) {
        for(auto v : element) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

Time complexity:
O(sumOfLenths*26*log(n))
that is (sumOfLength * log(n)) where n = number of words, sumOfLength = sum of lengths of all words

Space complexity:
O(sumOfLength)

*/
