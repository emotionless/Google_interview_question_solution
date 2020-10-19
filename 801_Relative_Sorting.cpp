#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;
const int MOD = 1000000007;
const int base = 31;

int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<vector<int>> dp1(n, vector<int>(2, n+1)), dp2(n, vector<int>(2, n+1));
    dp1[n-1][0] = 0;
    dp1[n-1][1] = 1;

    dp2[n-1][0] = 0;
    dp2[n-1][1] = 1;

    for(int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i+1] && )
        dp1[i][0] = dp1[i+1][0];
        dp2[i][0] = dp2[i+1][0];

        dp1[i][1] = 1 + dp2[i+1][0];
        dp2[i][1] = 1 + dp1[i+1][0];
    }



}

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
