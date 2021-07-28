/*
Link: https://leetcode.com/discuss/interview-question/1365988/Google-or-First-Round-or-Find-Number-of-Passing-Students

Given 2 arrays or vectors of scores in 2 subjects of N students.
A student will fail if any other student has obtained more marks in both the subjects.
Find the number of passing students.

Example:

Input:
Student 1: {100 , 80}
Student 2: {90 , 70}
Student 3: {60 , 80}
Student 4: {60 , 70}

Output:
2

Explanation:
Student 2 has less marks in both subjects than student 1, so failed.
Student 4 has less marks in both subjects than student 1, so failed.
How to solve the question in O(N^2) and also in better time complexity than O(N^2) ?
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

struct comparator {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first)
            return -a.second < -b.second;
        return -a.first < -b.first;
    }
};

int numberOfPassedStudents(vector< pair<int, int> > students) {
    sort(students.begin(), students.end(), comparator());
    int n = students.size();
    int j = 0;
    int mx = 0;
    int fail = 0;
    for (int i = 0; i < n; i++) {
        cout << students[i].first << " " << students[i].second << endl;
        while (j < i && students[j].first > students[i].first) {
            mx = max(mx, students[j].second);
            j++;
        }
        if (mx > students[i].second) {
            fail++;
        }
    }
    return n - fail;
}

int main() {
    vector< pair<int, int> > arr;
    arr.push_back({100, 80});
    arr.push_back({90, 70});
    arr.push_back({60, 70});
    arr.push_back({80, 80});

    cout << numberOfPassedStudents(arr) << endl;

    return 0;
}
