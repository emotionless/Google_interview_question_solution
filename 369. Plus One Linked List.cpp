/*
Link: https://leetcode.com/problems/plus-one-linked-list/

Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.



Example 1:

Input: head = [1,2,3]
Output: [1,2,4]
Example 2:

Input: head = [0]
Output: [1]


Constraints:

The number of nodes in the linked list is in the range [1, 100].
0 <= Node.val <= 9
The number represented by the linked list does not contain leading zeros except for the zero itself
*/

// solved by Milon

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
    bool plus1(ListNode *cur) {
        if (cur == nullptr) return true;
        cur -> val += plus1(cur->next);
        int ret = cur->val/10;
        cur->val %= 10;
        return ret;
    }

    ListNode* plusOne(ListNode* head) {
        if (plus1(head)) {
            return new ListNode(1, head);
        }
        return head;
    }
    */
    ListNode* plusOne(ListNode* head) {
        ListNode *notNine = new ListNode(0);
        ListNode *ans = head;
        bool check = false;
        while (head != nullptr) {
            if (head->val != 9)
                check = true, notNine = head;
            head = head -> next;
        }
        notNine->val++;
        if (check == false) {
            notNine -> next = ans;
            ans = notNine;
        }
        notNine = notNine -> next;
        while (notNine != nullptr) {
            notNine -> val = 0;
            notNine = notNine -> next;
        }
        return ans;
    }

};
