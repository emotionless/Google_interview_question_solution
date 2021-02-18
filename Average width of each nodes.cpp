/*
Problem link: https://leetcode.com/discuss/interview-question/1069991/Google-Interview-Question
Solved by: emotionless
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode *> children;
    TreeNode(int x) {
        val = x;
        for(int i = 0; i < children.size(); i++) {
            children[i] = nullptr;
        }
    }
};

pair<int, int> dfs(TreeNode *cur, map<int, double> &ans) {
    if (cur == nullptr) return {0, 0};
    int sum = 1;
    int cnt = 0;
    for(auto x : cur->children) {
        auto child = dfs(x, ans);
        sum += child.first;
        cnt = max(cnt, child.second);
    }
    cnt++;
    ans[cur->val] = (1.0*sum) / (1.0*cnt);

    return {sum, cnt};
}

map<int, double> averageWidth(TreeNode *root) {
    map<int, double> ans;

    dfs(root, ans);

    return ans;
}

int main() {
    TreeNode *root = new TreeNode(1);
    TreeNode *lft = new TreeNode(2);
    lft->children.push_back(new TreeNode(4));
    lft->children.push_back(new TreeNode(5));
    TreeNode *rgt = new TreeNode(3);
    rgt->children.push_back(new TreeNode(6));
    rgt->children.push_back(new TreeNode(7));

    root->children.push_back(lft);
    root->children.push_back(rgt);

    auto ans = averageWidth(root);
    for(auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}

/*



*/
