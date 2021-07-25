/*
Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/

Given the root of a binary tree, return the length of the longest consecutive path in the tree.

This path can be either increasing or decreasing.

For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid.
On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.



Example 1:


Input: root = [1,2,3]
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
Example 2:


Input: root = [2,1,3]
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].


Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-3 * 104 <= Node.val <= 3 * 104
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

    pair<int, int> traverse(TreeNode* cur, int &ans) {
        if (cur == nullptr)
            return make_pair(0, 0);
        auto left = traverse(cur->left, ans);
        auto right = traverse(cur->right, ans);
        int increasingLen = 1, decreasingLen = 1;
        if (cur->left != nullptr) {
            if (cur->left->val == (cur->val + 1)) {
                increasingLen = max(increasingLen, 1 + left.second);
            } else if (cur->left->val == (cur->val - 1)) {
                decreasingLen = max(decreasingLen, 1 + left.first);
            }
        }
        if (cur->right != nullptr) {
            if (cur->right->val == (cur->val + 1)) {
                increasingLen = max(increasingLen, 1 + right.second);
            } else if (cur->right->val == (cur->val - 1)) {
                decreasingLen = max(decreasingLen, 1 + right.first);
            }
        }
        ans = max(ans, increasingLen);
        ans = max(ans, decreasingLen);
        ans = max(ans, increasingLen + decreasingLen - 1);
        return make_pair(decreasingLen, increasingLen);
    }

    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
};
