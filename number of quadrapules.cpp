/*
Problem link: https://leetcode.com/discuss/interview-question/1069588/Media.net-interview-question
Solved by: emotionless
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Media {
public:
    Media(vector<int> _arr) {
        arr = _arr;
        dp.clear();
    }

    int numberOfQuandrapules() {
        int n = arr.size();
        dp.resize(n, vector<int>(4, 0));
        for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i][1] += dp[j][0];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if (arr[j] < arr[i]) {
                    dp[i][2] += dp[j][1];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    dp[i][3] += dp[j][2];
                }
            }
            ans += dp[i][3];
        }
        return ans;
    }


private:
    vector<int> arr;
    vector<vector<int>> dp;
};

int main()
{
    vector<int> arr{6,1,5,7,2,4,3};
    Media media = Media(arr);
    cout << media.numberOfQuandrapules() << endl;

    return 0;
}

/*



*/
