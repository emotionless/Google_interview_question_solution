/*
Problem link: https://leetcode.com/problems/largest-bst-subtree/
Solution Author: emotionless
Date: 26 April 2021

*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>


using namespace std;

// Solved by Milon

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

    pair<pair<int, int>, int> getLargestBST(TreeNode *cur) {
        if (cur -> left == nullptr && cur -> right == nullptr) return {{cur->val, cur->val}, 1};
        else if (cur->left == nullptr) {
            auto rgt = getLargestBST(cur->right);
            if (cur->val < rgt.first.first) {
                ans = max(ans, 1 + rgt.second);
                return {{cur->val, rgt.first.second}, rgt.second + 1};
            }
            return {{INT_MIN, INT_MAX}, 0};

        } else if (cur->right == nullptr) {
            auto lft = getLargestBST(cur->left);
            if (cur->val > lft.first.second) {
                ans = max(ans, 1 + lft.second);
                return {{lft.first.first, cur->val}, lft.second + 1};
            }
            return {{INT_MIN, INT_MAX}, 0};
        } else {
            auto lft = getLargestBST(cur->left);
            auto rgt = getLargestBST(cur->right);
            // cout << lft.first.second << " " << cur->val << " " << rgt.first.first << endl;
            if (lft.first.second < cur->val && cur->val < rgt.first.first && lft.first.second != INT_MIN && rgt.first.first != INT_MAX) {
                ans = max(ans, 1 + lft.second + rgt.second);
                // cout << 1 + lft.second + rgt.second << endl;
                return {{lft.first.first, rgt.first.second}, 1 + lft.second + rgt.second};
            } else {
                return {{INT_MIN, INT_MAX}, 0};
            }
        }
    }

    int getSize(TreeNode *cur) {
        if (cur == nullptr) return 0;
        return 1 + getSize(cur->left) + getSize(cur->right);
    }

    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) return 0;
        ans = 1;
        getLargestBST(root);
        return ans;
    }
private:
    int ans = 0;
};

/*
Time complexity:
O(n)
Space complexity:
O(d), depth of tree for recursion
*/
