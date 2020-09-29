#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <unordered_map>


using namespace std;

int numOfUniqueChar(string str) {
    unordered_map<char, bool> vis;
    for(auto c : str) {
        vis[c] = true;
    }
    return vis.size();
}

int waysToSplit(string str) {
    unordered_map<char, int> counter1, counter2;
    int n = numOfUniqueChar(str);
    for(int i = 0; i < str.length(); i++) {
        counter2[str[i]]++;
    }
    int ans = 0;
    for(auto c : str) {
        counter2[c]--;
        if (counter2[c] == 0) {
            counter2.erase(c);
        }
        counter1[c]++;
        if (counter1.size() == counter2.size()) {
            ans++;
        }
//        cout << c << " " << ans << endl;
    }
    return ans;
}

int main() {
    cout << waysToSplit("ababa") << endl;
    cout << waysToSplit("aba") << endl;
    cout << waysToSplit("aaaa") << endl;

    return 0;
}
