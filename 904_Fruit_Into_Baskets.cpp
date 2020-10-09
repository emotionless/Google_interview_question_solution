class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        int j = 0;
        int mx = 0;
        unordered_map<int, int> counter;
        for(int i = 0; i < n; i++) {
            // cout << "sdf" << endl;
            while(j < n && counter.size() <= 2) {
                if (counter.find(tree[j]) != counter.end()) {
                    counter[ tree[j] ]++;
                    j++;
                } else if (counter.size() == 2) {
                    break;
                } else {
                    counter[ tree[j] ]++;
                    j++;
                }
            }
            mx = max(mx, j - i);

            counter[ tree[i] ]--;
            if (counter[ tree[i] ] == 0) {
                counter.erase(tree[i]);
            }
        }
        return mx;
    }
};

/*]

Time: O(n)
Space: O(1)

*/
