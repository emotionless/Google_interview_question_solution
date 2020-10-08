#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;

int timeToType(string keyboard, string text) {

    unordered_map<char, int> pos;
    for(int i = 0; i < keyboard.size(); i++) {
        pos[keyboard[i]] = i;
    }
    int pre = 0;
    int ans = 0;
    for(auto ch : text) {
        ans += abs(pre - pos[ch]);
        pre = pos[ch];
    }
    return ans;
}

int main()
{
    cout << timeToType("abcdefghijklmnopqrstuvwxy", "cba") << endl;
    return 0;
}

/*

Time complexity:
O(n)
Space complexity:
O(1)

*/
