/*
Link: https://leetcode.com/problems/generalized-abbreviation/

Given the root of a binary tree, find the largest subtree, which is also a Binary Search Tree (BST), where the largest means subtree has the largest number of nodes.

A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties:

The left subtree values are less than the value of their parent (root) node's value.
The right subtree values are greater than the value of their parent (root) node's value.
Note: A subtree must include all of its descendants.

Follow up: Can you figure out ways to solve it with O(n) time complexity?



Example 1:



Input: root = [10,5,15,1,8,null,7]
Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one. The return value is the subtree's size, which is 3.
Example 2:

Input: root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
Output: 2


Constraints:

The number of nodes in the tree is in the range [0, 104].
-10^4 <= Node.val <= 10^4
*/

// solved by Milon

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

    tuple<int, int, int> getLargestBST(TreeNode *cur) {
        if (cur == nullptr) {
            return {INT_MAX, INT_MIN, 0};
        }
        auto l = getLargestBST(cur->left);
        auto r = getLargestBST(cur->right);
        if (get<1>(l) < cur->val && cur->val < get<0>(r)) {
            return {min(get<0>(l), cur->val), max(get<1>(r), cur->val), 1 + get<2>(l) + get<2>(r)};
        } else {
            return {INT_MIN, INT_MAX, max(get<2>(l), get<2>(r))};
        }
    }

    int largestBSTSubtree(TreeNode* root) {
        return get<2>(getLargestBST(root));
    }
};
