/*
Link: https://leetcode.com/problems/sparse-matrix-multiplication/

Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2. You may assume that multiplication is always possible.



Example 1:


Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
Output: [[7,0,0],[-7,0,3]]
Example 2:

Input: mat1 = [[0]], mat2 = [[0]]
Output: [[0]]


Constraints:

m == mat1.length
k == mat1[i].length == mat2.length
n == mat2[i].length
1 <= m, n, k <= 100
-100 <= mat1[i][j], mat2[i][j] <= 100
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
