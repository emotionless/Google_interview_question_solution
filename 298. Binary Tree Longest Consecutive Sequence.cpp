/*
Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

Given the root of a binary tree, return the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path needs to be from parent to child (cannot be the reverse).



Example 1:


Input: root = [1,null,3,2,4,null,null,null,5]
Output: 3
Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
Example 2:


Input: root = [2,null,3,2,null,1]
Output: 2
Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.


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
    void dfs(TreeNode *cur, int counter, int pre, int &ans) {
        if (cur == nullptr) {
            return;
        }
        if (cur->val == (pre + 1)) {
            counter++;
        } else {
            counter = 1;
        }
        ans = max(ans, counter);
        dfs(cur->left, counter, cur->val, ans);
        dfs(cur->right, counter, cur->val, ans);

        return;
    }
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        if (root == nullptr) return ans;
        dfs(root, 0, root->val, ans);
        return ans;
    }
};
