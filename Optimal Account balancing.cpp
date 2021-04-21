/*
Link: https://leetcode.com/discuss/interview-question/609750/Google-or-Phone-or-Optimal-Account-Balancing

You are given an array of transactions transactions where transactions[i] = [fromi, toi, amounti] indicates that the person with ID = fromi gave amounti $ to the person with ID = toi.

Return the minimum number of transactions required to settle the debt.

*/


class Solution {
public:
    const int INF = 100000;
    int minTransaction(int mask, vector<int> arr) {
        if (mask == ((1<<arr.size()) - 1)) {
            return 0;
        }
        int &ret = dp[mask];
        if (ret != -1) return ret;
        ret = INF;
        for (int i = 0; i < (arr.size()); i++) {
            if (!(mask&(1<<i))) {
                int tmp = arr[i];
                arr[i] = 0;
                for (int j = i + 1; j < arr.size(); j++) {
                    if (!(mask&(1<<j))) {
                        int newMask = mask|(1<<i);
                        arr[j] += tmp;
                        if (arr[j] == 0) newMask = newMask | (1<<j);
                        ret = min(ret, 1 + minTransaction(newMask, arr));
                        arr[j] -= tmp;
                    }
                }
                arr[i] = tmp;
            }
        }
        return ret;
    }

    int minTransfers(vector<vector<int>>& transactions) {
        int n = transactions.size();
        vector<int> amount(21, 0);
        for (auto v : transactions) {
            amount[v[0]] -= v[2];
            amount[v[1]] += v[2];
        }
        int ans = 0;
        unordered_map<int, int> cnt;
        vector<int> arr;
        for (int i = 0; i < 21; i++) {
            if (amount[i] == 0) continue;
            arr.push_back(amount[i]);
        }

        sort(arr.begin(), arr.end());
        int sz = arr.size();
        dp.resize((1<<sz) + 10, -1);
        for (auto v : arr) {
            cout << v << " ";
        }
        cout << endl;

        return minTransaction(0, arr);
    }
private:
    vector<int> dp;
};

/*

1 -8
5
*/
