/*
Link: https://leetcode.com/discuss/interview-question/753232/Google-or-Phone-or-Find-the-load-of-key

Given a String key and it's load, with two operations below:

addLoad(key: String, load: double): void
getLoad(key: String): double
Return the total load for a given key.
Note:
key: [a-zA-Z_][24] (case sensitive)
value: double
Example:

addLoad("Hello", 2.0);
addLoad("Hell", 3.0)
addLoad("He", 4.0);
getLoad("H") --> Should return 2 + 3 + 4 = 9
getLoad("he") --> Should return 0 (as there is no entry for lowercase h)
getLoad("Hell") --> Should return 3 + 2 = 5
Follow up question:
Suppose the key has a time-to-live in secs, how would you go about it.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:

    Solution() {
        root = new Node();
        curTime = 0;
    }

    void addLoad(string key, double load, int ttl) {
        curTime++;
        insert(key, load, ttl);
    }

    double getLoad(string key) {
        curTime++;
        Node *cur = root;
        for (auto ch : key) {
            int id = (ch <= 'Z'? ch - 'A' : 26 + ch - 'a');
            if (cur -> next[id] == nullptr)
                return 0.0;
            cur = cur -> next[id];
        }
        auto &pq = cur->pq;
        while (!pq.empty()) {
            MetaData top = pq.top();
            if (curTime <= top.time)
                break;
            pq.pop();
            cur->sum -= top.load;
        }
        return cur->sum;
    }

private:
    int curTime = 0;
    struct MetaData {
        double load;
        int time;
        MetaData(double l, int t) {
            load = l;
            time = t;
        }
    };

    struct Comparator {
        bool operator()(MetaData a, MetaData b) {
            return -a.time < -b.time;
        }
    };

    struct Node {
        priority_queue<MetaData, vector<MetaData>, Comparator> pq;
        double sum;
        Node *next[52];
        Node() {
            while (!pq.empty())
                pq.pop();
            sum = 0.0;
            for (int i = 0; i < 52; i++) {
                next[i] = nullptr;
            }
        }
    };
    Node *root = nullptr;


    void insert(string key, double load, int ttl) {
        Node *cur = root;
        for (auto ch : key) {
            int id = (ch <= 'Z'? ch - 'A' : 26 + ch - 'a');
            if (cur -> next[id] == nullptr)
                cur -> next[id] = new Node();
            cur = cur -> next[id];
            cur->pq.push(MetaData(load, curTime + ttl));
            cur->sum += load;
        }
        return;
    }
};


int main() {
    Solution sl = Solution();

    sl.addLoad("Hello", 2.1, 3);
    sl.addLoad("Hell", 3.0, 100);
    sl.addLoad("He", 4.0, 1);
    cout << sl.getLoad("H") << endl; // --> Should return 2.1 + 3 + 4 = 9.1
    cout << sl.getLoad("H") << endl; // --> Should return 0 + 3 + 0 = 3
    cout << sl.getLoad("he") << endl; // --> Should return 0 (as there is no entry for lowercase h)
    cout << sl.getLoad("Hell") << endl; // --> Should return 0 + 3 + 0 = 3

    return 0;
}
