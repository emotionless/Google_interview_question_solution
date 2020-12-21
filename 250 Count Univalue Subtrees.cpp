/*
Problem link:  https://leetcode.com/problems/count-univalue-subtrees/

Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.



Example 1:

Input: root = [5,1,5,5,5,null,5]
Output: 4


Example 2:

Input: root = []
Output: 0


Example 3:

Input: root = [5,5,5,5,5,null,5]
Output: 6

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

    bool solve(const TreeNode *cur, int &ans) {
        if (cur == nullptr) return true;
        bool okay = solve(cur -> left, ans) & solve(cur -> right, ans);
        if (cur->left && cur->left -> val != cur->val) okay = false;
        if (cur->right && cur->right -> val != cur->val) okay = false;

        if (okay) ans++;
        return okay;
    }

    int countUnivalSubtrees(const TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
