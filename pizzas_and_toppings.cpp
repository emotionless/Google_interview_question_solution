#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <climits>


using namespace std;

class PizzaAndToppings {
public:

    bool needToDecrease(const int a, const int b, const int cur) {
        if (remaining < mn) {
            mn = min(mn, remaining);
            ans = cur;
        }
        if (abs(a - remaining) < mn) {
            mn = min(mn, abs(a - remaining));
            ans = cur + a;
        }
        if (abs(b - remaining) < mn) {
            mn = min(mn, abs(b - remaining));
            ans = cur + b;
        }
        if (abs(a + b - remaining) < mn) {
            mn = min(mn, abs(a + b - remaining));
            ans = cur + a + b;
        }

        if ((a+b) >= remaining) return true;
        return false;
    }

    int getMinCost(const vector<int> pizzas, vector<int> toppings, const int x) {
        remaining = 0;
        mn = INT_MAX;
        ans = -1;
        sort(toppings.begin(), toppings.end());
        for(auto cur : pizzas) {
            remaining = x - cur;
            if (remaining < 0) continue;

            for(int i = 0, j = toppings.size() - 1; i <= j; i++, j--) {
                if (needToDecrease(toppings[i], toppings[j], cur)) {
                    j--;
                } else {
                    i++;
                }
            }
        }
        return ans;
    }



private:
    int remaining = 0;
    int mn = INT_MAX;
    int ans = -1;
};
int main()
{
    vector<int> pizzas({800, 850, 900});
    vector<int> toppings({100, 150});

    PizzaAndToppings pt;

    cout << pt.getMinCost(pizzas, toppings, 1000) << endl;
    cout << pt.getMinCost({850, 900}, {200, 250}, 1000) << endl;

    return 0;
}

/*

Time complexity:
O(sumOfLenths*26*log(n))
that is (sumOfLength * log(n)) where n = number of words, sumOfLength = sum of lengths of all words

Space complexity:
O(sumOfLength)

*/
