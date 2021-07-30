/*
Link: https://leetcode.com/discuss/interview-question/364396/Google-or-Product-of-the-Last-K-Numbers

Design a data structure to calculate the moving product of all elements in a sliding window of size k.

class SlidingWindow {

    public SlidingWindow(int k) {
    }

    public void add(int val) {
    }

	public int getProduct() {
	}
}
All methods should work in O(1) time.

Example:

SlidingWindow window = new SlidingWindow(3);
window.add(1); // [1]
window.add(2); // [1, 2]
window.getProduct(); // 2
window.add(3); // [1, 2, 3]
window.getProduct(); // 6
window.add(4); // [2, 3, 4]
window.getProduct(); // 24
Follow-up:
What if k is a method argument instead of constructor?

public int getProduct(int k) {
}
You can assume that a product will fit into a single 32-bit integer without overflowing.

*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class SlidingWindow {
public:
    SlidingWindow() {

    }

    void add(int val) {
        if (val == 0) {
            while (container.size())
                container.pop();
        }
        if (container.size() == 0 || container.top().first != val) {
            container.push({val, 1});
        } else {
            container.top().second++;
        }
    }

    int getProduct(int k) {
        stack<pair<int, int>> rev;
        int ans = 1;
        while (!container.empty()) {
            auto top = container.top();
            container.pop();
            rev.push(top);
            while (top.second > 0 && k > 0) {
                ans = ans * top.first;
                top.second--;
                k--;
            }
            if (k == 0) {
                break;
            }
        }
        while (rev.size()) {
            container.push(rev.top());
            rev.pop();
        }
        return ans;
    }
private:
    stack<pair<int, int>> container;
};


int main() {
    SlidingWindow window = SlidingWindow();
    window.add(1); // [1]
    window.add(2); // [1, 2]
    cout << window.getProduct(3) << endl; // 2
    window.add(3); // [1, 2, 3]
    cout << window.getProduct(3) << endl; // 6
    window.add(4); // [2, 3, 4]
    cout << window.getProduct(3) << endl; // 24

    return 0;
}
