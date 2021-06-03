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

/*
long long getHash(string s) {
    long long sum = 0;
    for(auto ch : s) {
        sum = ((sum * base) % MOD + (ch - 'a'))%MOD;
    }
    return sum;
}
*/

vector<vector<string>> groupStrings(vector<string> strings) {
    /*
    int mxLen = 0;
    for(auto s : strings) {
        mxLen = max(mxLen, s.length());
    }
    long long power_sum[mxLen + 26];
    power_sum[0] = 0;

    for(int i = 1; i <= 100000; i++) {
        power_sum[i] = power_sum[i-1] +
    }
    */
    vector<vector<string>> ans;
    unordered_map<string, int> container;
    int cnter = 0;
    for(auto s : strings) {
        bool found = false;
        for(int i = 0; i < 26; i++) {
            string cur = s;
            for(int j = 0; j < cur.length(); j++) {
                cur[j] = (char)((cur[j] - 'a' + i + 26) % 26 + 'a');
            }
            if (container.find(cur) != container.end()) {
                found = true;
                int indx = container[cur];
                ans[indx].push_back(s);
                break;
            }
        }
        if (found == false) {
            ans.push_back(vector<string>({s}));
            container[s] = cnter;
            cnter++;
        }
    }

    return ans;
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
