class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[n-1][0] = dp[n-1][1] = 1;
        map<int, int> container;
        int ans = 1;
        container[A[n-1]] = n-1;
        for(int i = n-2; i >= 0; i--) {
            auto it = container.lower_bound(A[i]+1);
            // cout << "For: " << i << endl;
            if (it == container.begin()) {
                dp[i][1] = 0;
            } else {
                it--;
                // cout << it->second << endl;
                dp[i][1] = dp[it->second][0];
            }
            it = container.upper_bound(A[i] - 1);
            if (it == container.end()) {
                dp[i][0] = 0;
            } else {
                // cout << "U " <<it->second << endl;
                dp[i][0] = dp[it->second][1];
            }
            container[A[i]] = i;
            ans += dp[i][0];
        }
        return ans;
    }
};
