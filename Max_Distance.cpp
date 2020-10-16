#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;

struct node {
    int sum = 0;
    node *nxt[2];
    node() {
        sum = 0;
        nxt[0] = nxt[1] = nullptr;
    }
};
int ans = 0;
int len = 0;
void insert(node *cur, const string str, int ind) {
    if (ind == str.length()) {
        cur->sum = 1;
        return;
    }
//    cout << ind << endl;
    int id = str[ind] - '0';
    if (cur->nxt[id] == nullptr) {
        cur->nxt[id] = new node();
    }
    ans = max(ans, (cur->nxt[1-id]?(cur->nxt[1-id]->sum + len - ind) : 0));
    insert(cur -> nxt[id], str, ind + 1);
    cur->sum = 1 + max(cur->nxt[0]?cur->nxt[0]->sum : 0, cur->nxt[1]?cur->nxt[1]->sum : 0);



    return;
}

int maxDistance(const vector<string> strs) {
    node *root = new node();
    for(auto v : strs) {
        len = v.length();
        insert(root, v, 0);
        cout << endl;
    }

    return ans;
}

int main()
{
    vector<string> leave({"1011000", "1011110"});

    cout << maxDistance(leave) << endl;
    return 0;
}

/*

Time complexity:
O(log(sumOfLen))
Space complexity:
O(sumOfLen)

*/
