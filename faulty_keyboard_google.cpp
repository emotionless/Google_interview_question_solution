#include <bits/stdc++.h>


using namespace std;

const string input = "I lik   to   xplor   univ rs ";
string dictionary[] = {"like", "explore", "toe", "universe", "rse"};

struct Tree {
    bool isEnd;
    Tree *next[52];
    Tree() {
        isEnd = false;
        for(int i = 0; i < 52; i++) {
            next[i] = NULL;
        }
    }
};



vector<string> answer;

void insert(Tree *cur, string str) {
    for(int i = 0; i < str.length(); i++) {
        int id = 0;
        if (str[i] <= 'Z') id = str[i] - 'A';
        else id = str[i] - 'a' + 26;

        if(cur -> next[id] == NULL) cur -> next[id] = new Tree();
        cur = cur -> next[id];
    }
    cur -> isEnd = true;

    return;
}

Tree *root = NULL;

vector<int> search(int st, int ed) {
    Tree *cur = root;
    vector<int> store;
    for(int i = st; i < ed; i++) {
        int id = 0;
        if (input[i] == ' ') id = 'e' - 'a' + 26;
        else if (input[i] <= 'Z') id = input[i] - 'A';
        else id = input[i] - 'a' + 26;

        if(cur -> next[id] == NULL) {
            return store;
        }
        cur = cur -> next[id];
        if (cur -> isEnd == true) {
            store.push_back(i);
        }
    }
    return store;
}

int mxLen = 0;
void backTrack(int ind, int ed, string cur) {
    if (ind == ed) {
        answer.push_back(cur);
        return;
    }
    backTrack(ind + 1, ed, cur + input[ind]);
    vector<int> jump_positions = search(ind, min(ed, ind + mxLen));
    // cout << jump_positions.size() << " ";
    for(int i = 0; i < jump_positions.size(); i++) {
        string newStr = input.substr(ind, jump_positions[i] - ind + 1);
        for(int j = 0; j < newStr.length(); j++) {
            if (newStr[j] == ' ') newStr[j] = 'e';
        }
        backTrack(jump_positions[i] + 1, ed, cur + newStr);
    }
    return;
}

int main() {
    // https://leetcode.com/discuss/interview-question/643158/Google-or-Phone-or-Faulty-Keyboard
    root = new Tree();
    for(int i = 0; i < 5; i++) {
        insert(root, dictionary[i]);
        mxLen = max(mxLen, (int)dictionary[i].length());
    }

    backTrack(0, input.length(), "");

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }



    return 0;
}

/*


*/
