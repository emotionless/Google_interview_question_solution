#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cassert>


using namespace std;
set<pair<int, int>> container;
vector<bool> valid;

bool isValid(int num) {
    return valid[num];
}

template<typename T>
void pop_front(vector<T> &vec) {
    if (vec.size() > 0) {
        vec.erase(vec.begin());
    }
    return;
}

vector<vector<int>> mat;

int main()
{
    int n, m;
    cin >> m >> n;
    vector<vector<int>> arr(n, vector<int>(m, -1));
    valid.resize(m + 1, true);
    mat.resize(m+1);
    int counter[m+1];
    memset(counter, 0, sizeof counter);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (j == 0) {
                counter[ arr[i][j] ]++;
                mat[ arr[i][j] ].push_back(i);
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        container.insert(make_pair(counter[i], i));
    }
    int num = 0;

    for(int k = 1; k < m ; k++) {
        for(auto i : mat[num]) {
            while(!isValid(arr[i][0])) {
                pop_front(arr[i]);
            }
            int fruit = arr[i][0];
            auto it = container.find(make_pair(counter[fruit], fruit));
            container.erase(it);
            counter[ fruit ]++;
            container.insert(make_pair(counter[fruit], fruit));
            mat[ fruit ].push_back(i);
        }
        int cnt = INT_MAX;
        num = -1;
        auto it = container.begin();
        num = it->second;
//        for(int i = 1; i <= m; i++) {
//            if (!isValid(i)) {
//                continue;
//            }
//            if (counter[i] < cnt) {
//                cnt = counter[i];
//                num = i;
//            }
//            cout << i << " " << counter[i] << endl;
//        }
        if (num == -1) assert(0);

        valid[num] = false;
//        cout << num << " " << it->first << endl;
        container.erase(it);
    }
    cout << "Ans: " << endl;
    for(int i = 1; i <= m; i++) {
        if (isValid(i)) {
            cout << i << endl;
        }
    }

    return 0;
}

/*
input:
3 2
1 2 3
2 3 1

4 5
1 2 3 4
1 2 3 4
2 4 3 1
3 4 2 1
4 3 2 1

2 1
2 1

Output:
2
2

Time complexity:
O(m*n)

Space complexity:
O(m)

*/
