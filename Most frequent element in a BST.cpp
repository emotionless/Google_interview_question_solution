/*
Link: https://leetcode.com/discuss/interview-question/963428/Google-or-Phone-or-Most-frequent-element-in-a-BST
Solved by: emotionless

Given a BST with duplicates, how do you find out the most frequent value?

            50
         /          \
      40             58
   /	  \         /    \
  40      40       58     62
Most frequent element is 40.

*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *left, *right;
    ListNode(int v) {
        val = v;
        left = right = nullptr;
    }
};

class BST {
public:
    BST(ListNode *node) {
        head = node;
    }
    int getMostFrequentValue() {
        mx = 0, ans = -1;
        getMostFrequentValueFromTree(head);
        return ans;
    }
private:
    ListNode *head;
    int mx, ans;

    int getMostFrequentValueFromTree(ListNode *cur) {
        if (cur == nullptr)
            return 0;
        int l = getMostFrequentValueFromTree(cur -> left);
        int r = getMostFrequentValueFromTree(cur -> right);
        int ret = 1;
        if (cur -> left != nullptr) {
            ret += (cur -> left -> val == cur -> val? l : 0);
        }
        if (cur -> right != nullptr) {
            ret += (cur -> right -> val == cur -> val? r : 0);
        }
        if (ret > mx) {
            ans = cur -> val;
            mx = ret;
        }
        return ret;
    }
};


int main() {
    ListNode *head = new ListNode(50);
    ListNode *l = new ListNode(40);
    ListNode *r = new ListNode(58);
    head -> left = l;
    head -> right = r;
    l -> left = new ListNode(40);
    l -> right = new ListNode(40);

    r -> left = new ListNode(58);
    r -> right = new ListNode(62);

    BST bst = BST(head);
    cout << bst.getMostFrequentValue() << endl;

    return 0;
}

/*

Time complexity: O(n)
Space complexity: O(h), h = height of the tree

*/
