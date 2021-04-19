/*
Link:  https://leetcode.com/discuss/interview-question/672160/Google-or-Phone-or-Street-Fighter

Create an API, which will have two functions
Register -- which takes sequence of keys and register a special move, Like in a street fighter game UDLR(up, down, left, right) can be registered to special move "Fireball".
emit --takes a single key and returns the list of registered sequence(s) that were completed by key press

register("UDLR", "Fireball");
register("DLRU", "Punch");
register("LR", "Kick");
emit("U");
emit("D");
emit("L");
emit("R"); -- returns a list containing {"Fireball" and "kick"}
emit("U"); -- return a {"Punch"}
emit("U");
emit("U");
emit("U");---- returns a list containing {"Fireball" and "kick"

*/

class StreamChecker {
public:

    struct Trie {
        bool isEnd;
        Trie *next[26];
        Trie() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };

    StreamChecker(vector<string>& words) {
        root = new Trie();
        for (auto str : words) {
            len = max(len, (int)str.length());
            reverse(str.begin(), str.end());
            insert(str);
        }
    }

    bool query(char letter) {
        buffer += letter;
        Trie *cur = root;
        sz++;
        for (int i = sz - 1; i >= max(0, sz - len); i--) {
            int id = buffer[i] - 'a';
            cur = cur->next[id];
            if (cur == nullptr) return false;
            if (cur->isEnd) return true;
        }
        return cur->isEnd;
    }
private:
    Trie *root = nullptr;
    string buffer = "";
    int len = 0;
    int sz = 0;
    void insert(string &str) {
        Trie *cur = root;
        for (int i = 0; i < str.length(); i++) {
            int id = str[i] - 'a';
            if (cur->next[id] == nullptr) cur->next[id] = new Trie();
            cur = cur->next[id];
        }
        cur->isEnd = true;
    }



};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
