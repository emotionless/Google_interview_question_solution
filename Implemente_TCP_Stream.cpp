/*
Link: https://leetcode.com/discuss/interview-question/746360/Google-or-Phone-or-Implement-TCP-stream

Implement a minimal TCP stream that can be read from, which supports the following two operations:
void onData(String data);
String read(int length);
The OS calls onData() when a packet arrives, and read() when any application wants to read from the stream.
Assume that
Packets always arrive in-order
Packets sent are not lost

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    void onData(string data) {
        buffer += data;
    }

    string read(int length) {
        if (length > buffer.length()) length = buffer.length();
        string ret = buffer.substr(0, length);
        buffer.erase(0, length);
        return ret;
    }
private:
    string buffer;
};


int main() {
    Solution sl = Solution();
    sl.onData("abcdefg");
    cout << sl.read(5) << endl;
    sl.onData("hijklmn");
    cout << sl.read(100) << endl;

    return 0;
}
