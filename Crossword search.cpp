/*
Link: https://leetcode.com/discuss/interview-question/1349302/Google-or-Phone-interview-or-Crossword-search

Given a r x c matrix and an input String of length n.
Check if the input string can fit in the matrix;
Rules

can occupy " ",
cannot occupy #
there should not be any leading or trailing spaces or other alphabets (# is ok).
Cannot update existing letters
You can place the string either horizontally (left to right) or vertically(top to bottom)
need to be stored contiguously in the same row/col
e.g
3 x 3 [
 "#", " ", "#"
 " ", " ", "#"
 "#", "c", " "
 ]
 str ->abc
 ans -> true
 "ab" can be placed as follows and "c" already exists:
 [
 "#", "a", "#"
 " ", "b", "#"
 "#", "c", " "
 ]


 2 x 2[
 " ", " "
 " ", " "
 ]
 str -> a
 ans-> false ( no matter where you place "a", there will be a leading or trailing space in the row or column)
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool isCrosswordPossible(const vector<char> &str, const string &pat) {
    int n = str.size();
    int m = pat.size();
    vector<int> positions;
    positions.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (str[i] == '#') {
            positions.push_back(i);
        }
    }
    positions.push_back(n);

    for (int i = 0; i < positions.size() - 1; i++) {
        int stInd = positions[i] + 1;
        int edInd = positions[i+1] - 1;
        if ((edInd - stInd + 1) != m) continue;
        int j = stInd;
        bool check = true;
        while (j <= edInd) {
            if (str[j] != ' ' && str[j] != pat[j - stInd]) {
                check = false;
                break;
            }
            j++;
        }
        if (check) {
            return true;
        }
    }
    return false;
}

bool isCrossWord(const vector<vector<char>> &input, string pat) {
    for (auto r : input) {
        if (isCrosswordPossible(r, pat)) {
            return true;
        }
    }
    for (int i = 0; i < input[0].size(); i++) {
        vector<char> col;
        for (int j = 0; j < input.size(); j++) {
            col.push_back(input[j][i]);
        }

        if (isCrosswordPossible(col, pat)) {
            return true;
        }
    }
    return false;
}

int main() {

    vector<vector<char>> inp{{'#', ' ', '#'}, {' ', ' ', '#'}, {'#', 'c', ' '}};
    string pat = "abc";

    cout << isCrossWord(inp, pat) << endl;

    vector<vector<char>> inp1{{' ', ' '}, {' ', ' '}};
    string pat1 = "abc";

    cout << isCrossWord(inp1, pat1) << endl;


    return 0;
}
