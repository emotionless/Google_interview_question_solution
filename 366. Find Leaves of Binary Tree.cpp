/*
Link: https://leetcode.com/problems/find-leaves-of-binary-tree/
Help from: https://leetcode.com/problems/find-leaves-of-binary-tree/discuss/83858/C%2B%2B-short-easy-understanding-DFS-solution


Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.


Example 1:


Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
Example 2:

Input: root = [1]
Output: [[1]]


Constraints:

The number of nodes in the tree is in the range [1, 100].
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

    int dfs(TreeNode *cur, vector<vector<int>> &ans) {
        if (cur == nullptr)
            return 0;
        int level = 1 + max(dfs(cur->left, ans), dfs(cur->right, ans));
        if (level > ans.size()) {
            ans.push_back({});
        }
        ans[level - 1].push_back(cur->val);
        return level;
    }

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans);
        return ans;
    }
};


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
    void makeParent(TreeNode *cur) {
        if (cur == nullptr)
            return;
        degree[cur] = 0;
        if (cur->left != nullptr) {
            parent[cur->left] = cur;
            degree[cur]++;
            makeParent(cur->left);
        }
        if (cur->right != nullptr) {
            parent[cur->right] = cur;
            degree[cur]++;
            makeParent(cur->right);
        }
        return;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        makeParent(root);
        queue<TreeNode*> q;
        for (auto v : degree) {
            if (v.second == 0) {
                q.push(v.first);
            }
        }

        vector<vector<int>> ans;
        while (q.size() > 0) {
            vector<int> curList;
            queue<TreeNode*> nextQ;
            while (!q.empty()) {
                TreeNode *cur = q.front();
                q.pop();
                curList.push_back(cur->val);
                if (parent.find(cur) != parent.end()) {
                    degree[parent[cur]]--;
                    if (degree[parent[cur]] == 0) {
                        nextQ.push(parent[cur]);
                    }
                }
            }
            ans.push_back(curList);
            q = nextQ;
        }
        return ans;
    }
private:
    unordered_map<TreeNode*, int> degree;
    unordered_map<TreeNode*, TreeNode*> parent;
};
