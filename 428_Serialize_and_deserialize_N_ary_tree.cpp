/*
Problem link: https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

     1
   / | \
  3  2  4
 / \
5   6

as [1 [3[5 6] 2 4]]. Note that this is just an example, you do not necessarily need to follow this format.


*/

// Solved by: Milon

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(const Node* root) {
        if (root == nullptr) return "";
        string ret = to_string(root->val);
        if (root->children.size() == 0) return ret;
        ret += " [";
        for(auto v : root->children) {
            ret += " ";
            ret += serialize(v);
        }
        ret += " ]";
        return ret;
    }

    // Decodes your  << endl;
    Node* deserialize(const string data) {
        if (data.length() == 0 ) return NULL;
        stringstream ss(data);
        string tmp = "";
        stack<Node*> stak;
        ss>>tmp;
        Node *last = new Node(stoi(tmp));
        Node *ans = last;
        stak.push(last);
        while (ss >> tmp) {
            if (tmp == "[") {
                stak.push(last);
            } else if (tmp == "]") {
                stak.pop();
            } else {
                Node *top = stak.top();
                Node *cur = new Node(stoi(tmp));
                top->children.push_back(cur);
                last = cur;
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
