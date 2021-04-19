/*
Link:  https://leetcode.com/discuss/interview-question/668896/Google-or-Phone-or-Group-odd-valued-and-even-valued-nodes-in-Linked-List

You want to group all nodes with VALUEs that are even together and all nodes with VALUES that are odd together.

Ex:
Input: 2->1->3->5->6->4->7->NULL
Output: 1->3->5->7->2->6->4->NULL

Anyone know if there's a way of doing this in-place?

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int v) {
            val = v;
            next = nullptr;
        }
    };

    Solution(vector<int> nums) {
        ListNode *cur = root;
        for (auto v : nums) {
            if (cur == nullptr) {
                cur = new ListNode(v);
                root = cur;
            } else {
                cur -> next = new ListNode(v);
                cur = cur -> next;
            }
        }
    }

    void groupOddEven() {
        if (root == nullptr) return;
        ListNode *cur = root -> next;
        ListNode *pre = root;
        while (cur != nullptr) {
            if ((pre->val % 2) == (cur->val % 2)) {
                pre = pre -> next;
                swap(cur->val, pre->val);
            }
            cur = cur->next;
        }
        while (root != nullptr) {
            cout << root->val << " ";
            root = root -> next;
        }
        cout << endl;
        return;
    }
private:
    ListNode *root = nullptr;
};

int main() {
    Solution sl = Solution({ 2, 1, 3, 5, 6, 4, 7});
    sl.groupOddEven();

    Solution sl1 = Solution({1, 6, 3, 5, 7, 2, 7, 6, 4, 1});
    sl1.groupOddEven();




    return 0;
}
