/*
Link: https://leetcode.com/problems/construct-binary-tree-from-string/

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.



Example 1:


Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
Example 2:

Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]
Example 3:

Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]


Constraints:

0 <= s.length <= 3 * 104
s consists of digits, '(', ')', and '-' only.
*/

// solved by Milon+
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* traverse(int &ind, const string &s) {
        if (ind == s.length())
            return nullptr;
        bool neg = false;
        if (s[ind] == '-') {
            neg = true;
            ind++;
        }
        string num = "";
        while (ind < s.length() && isdigit(s[ind])) {
            num += s[ind++];
        }
        TreeNode *ret = new TreeNode(stoi(num));
        if (neg)
            ret->val *= -1;
        if (s[ind] == '(') {
            ind += 1;
            ret->left = traverse(ind, s);
            if (s[ind+1] == '(') {
                ind += 2;
                ret->right = traverse(ind, s);
            }
            ind++;
        } else if (s[ind] == ')') {
            return ret;
        }
        return ret;
    }
    TreeNode* str2tree(string s) {
        int ind = 0;
        return traverse(ind, s);
    }
};
