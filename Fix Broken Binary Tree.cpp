/*
Link:  https://leetcode.com/discuss/interview-question/621249/Google-or-Phone-or-Fix-Broken-Binary-Tree

Fix a broken binary tree which some nodes are pointing to wrong nodes in the Tree
In the example below, there are broken edges. The left child of Node 5 points to Node 2. The left child of Node 6 points to Node 4. The right child of Node 7 points to 1.


        1
	 /     \
    2       3
  /   \    /  \
 4     5  6    7


*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) {
        val = v;
        left = right = nullptr;
    }
};

class Solution{
public:
    TreeNode* fixBrokenBinaryTeee(TreeNode *head) {
        if (head == nullptr || vis.find(head) != vis.end()) {
            return nullptr;
        }
        vis.insert(head);
        head -> left = fixBrokenBinaryTeee(head -> left);
        head -> right = fixBrokenBinaryTeee(head -> right);

        return head;
    }

private:
    unordered_set<TreeNode*> vis;
};

void print(TreeNode *cur) {
    if (cur == nullptr) return;
    cout << cur->val<< "\n";

    print(cur->left);
    print(cur->right);

    return;
}

int main() {
    Solution sol = Solution();
    TreeNode *head = new TreeNode(1);
    TreeNode *left = new TreeNode(2);
    TreeNode *leaf4 = new TreeNode(4);
    TreeNode *leaf5 = new TreeNode(5);
    leaf5->left = left;
    left->left = leaf4;
    left->right = leaf5;
    head->left = left;
    TreeNode *right = new TreeNode(3);
    TreeNode *leaf6 = new TreeNode(6);
    TreeNode *leaf7 = new TreeNode(7);
    leaf6->left = leaf4;
    leaf7->right = head;
    right->left = leaf6;
    right->right = leaf7;
    head->right = right;

    auto ans = sol.fixBrokenBinaryTeee(head);

    print(ans);

    return 0;
}

