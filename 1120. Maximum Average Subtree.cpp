
/*
Link: https://leetcode.com/problems/maximum-average-subtree/

Given the root of a binary tree, find the maximum average value of any subtree of that tree.

(A subtree of a tree is any node of that tree plus all its descendants. The average value of a tree is the sum of its values, divided by the number of nodes.)
*/

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
    double ans = 0.0;
    pair<int, int> getAvg(TreeNode *cur) {
        if (cur == nullptr)
            return make_pair(0, 0);
        pair<int, int> l = getAvg(cur -> left);
        pair<int, int> r = getAvg(cur->right);
        ans = max(ans, 1.0*(l.first + r.first + cur->val)/((l.second + r.second + 1)*1.0));

        return make_pair(l.first + r.first + cur->val, l.second + r.second + 1);
    }

    double maximumAverageSubtree(TreeNode* root) {
        getAvg(root);

        return ans;
    }
};
