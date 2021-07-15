/*
Link: https://leetcode.com/problems/binary-tree-vertical-order-traversal/

Given the root of a binary tree, return the vertical order traversal of its nodes' values. (i.e., from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Example 2:


Input: root = [3,9,8,4,0,1,7]
Output: [[4],[9],[3,0,1],[8],[7]]
Example 3:


Input: root = [3,9,8,4,0,1,7,null,null,null,2,5]
Output: [[4],[9,5],[3,0,1],[8,2],[7]]
Example 4:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
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
    void bfs(TreeNode *root) {

        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, int> hashed;
        hashed[root] = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            store[hashed[cur]].push_back(cur->val);
            if (cur->left != nullptr) {
                q.push(cur->left);
                hashed[cur->left] = hashed[cur] - 1;
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
                hashed[cur->right] = hashed[cur] + 1;
            }
        }
        return;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr) return {};
        bfs(root);
        vector<vector<int>> ans;
        for (auto ele : store) {
            ans.push_back(ele.second);
        }
        return ans;
    }
private:
    map<int, vector<int>> store;
};
