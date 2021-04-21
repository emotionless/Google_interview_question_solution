/*
Link:  https://leetcode.com/discuss/interview-question/615526/Google-or-Phone-or-Print-BST-leaves-in-alternate-order

Question:
Given a BST. Print leaf nodes of the tree in following order: 1st, nth, 2nd, (n-1)th, 3rd,........

Example:

Input:
	   5
	 /   \
	3     8
   / \   / \
  1   4 6   9

Outut: 1, 9, 4, 6
My solution :
I used DFS traversal to store all leaf nodes in an array and then print leaf nodes in expected order in a for loop over array.

I was given feedback that I could solve it with better complexity. Can anyone suggest solution with better complexity?

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right, *pre, *next;

    TreeNode(int v) {
        val = v;
        left = right = pre = next = nullptr;
    }
};

class Solution{
public:

    void connect(TreeNode *cur) {
        if (last == nullptr) {
            last = ans = cur;
        } else {
            last->next = cur;
            cur->pre = last;
            last = last->next;
        }
    }

    void traversePreorder(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }
        if (cur->left == nullptr && cur->right == nullptr) {
            connect(cur);
            return;
        }
        traversePreorder(cur->left);
        traversePreorder(cur->right);

        return;
    }

    void printBSTLeaves(TreeNode *head) {
        traversePreorder(head);
        bool isEven = true;
        while (ans != last) {
            if (isEven) {
                cout << ans->val << " ";
                ans = ans->next;
            } else {
                cout << last->val << " ";
                last = last->pre;
            }
            isEven = true ^ isEven;
        }
        cout << ans->val << endl;

        return;
    }
private:
    TreeNode *last = nullptr, *ans = nullptr;
};


int main() {
    Solution sol = Solution();
    TreeNode *head = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *leaf4 = new TreeNode(4);
    TreeNode *leaf5 = new TreeNode(5);
    left->left = leaf4;
    left->right = leaf5;
    head->left = left;
    TreeNode *right = new TreeNode(3);
    TreeNode *leaf6 = new TreeNode(6);
    TreeNode *leaf7 = new TreeNode(7);
    right->left = leaf6;
    right->right = leaf7;
    head->right = right;

    sol.printBSTLeaves(head);


    return 0;
}

