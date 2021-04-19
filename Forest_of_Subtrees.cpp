/*
Link:  https://leetcode.com/discuss/interview-question/667176/Google-or-Phone-or-Forest-of-Sub-Trees

Given a binary tree and a collection of nodes to exclude, compute the collection of subtrees resulting from excluding the nodes. Restriction: the original tree should not be modified and a forest of subtrees should have copied nodes.

Example:

	  A
	/   \
   B     C*
  / \     \
 D*   E    F
/ \
G   H
Nodes to exclude: [D, C] - nodes

Result (copies of original nodes):
```
[ A', F', G', H' ]
/
B'
\
E'

*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    char ch;
    TreeNode *left, *right;
    TreeNode(char c) {
        ch = c;
        left = right = nullptr;
    }
};


class Solution {
public:
    void DFS(TreeNode *cur, bool canTake, vector<TreeNode*> &res) {
        if (cur == nullptr) return;
        if (ignoresList.find(cur->ch) != ignoresList.end()) {
            DFS(cur->left, true, res);
            DFS(cur->right, true, res);
            cur->left = cur->right = nullptr;
        } else {
            DFS(cur->left, false, res);
            DFS(cur->right, false, res);
            if (canTake) {
                res.push_back(cur);
            }
            if (cur->left != nullptr && ignoresList.find(cur->left->ch) != ignoresList.end()) {
                cur->left = nullptr;
            }
            if (cur->right != nullptr && ignoresList.find(cur->right->ch) != ignoresList.end()) {
                cur->right = nullptr;
            }
        }
    }

    vector<TreeNode*> forestOfSubTrees(TreeNode *root, vector<char> ignores) {
        for (auto ch : ignores) {
            ignoresList.insert(ch);
        }
        vector<TreeNode*> result;
        DFS(root, true, result);
        return result;
    }
private:
    unordered_set<char> ignoresList;
};

int main() {
    TreeNode *tn = new TreeNode('A');
    tn->left = new TreeNode('B');
    tn->right = new TreeNode('C');
    tn->right->right = new TreeNode('F');
    tn->left->left = new TreeNode('D');
    tn->left->right = new TreeNode('E');

    tn->left->left->left = new TreeNode('G');
    tn->left->left->right = new TreeNode('H');
    Solution sl = Solution();
    auto ans = sl.forestOfSubTrees(tn, {'D', 'C'});

    for (auto v : ans) {
        cout << v->ch << " ";
    }
    cout << endl;

    return 0;
}
