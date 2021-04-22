/*
Link: https://leetcode.com/discuss/interview-question/603504/Google-or-Phone-or-Bounding-box-of-connected-component

You are given an image that is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel.

The black pixels are connected (i.e., there is only one black region). Pixels are connected horizontally and vertically.

Given two integers x and y that represent the location of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.



Example 1:

Input: image = [["0","0","1","0"],["0","1","1","0"],["0","1","0","0"]], x = 0, y = 2
Output: 6

*/
// Milon

class Solution {
public:

    bool doesContain(int x1, int y1, int x2, int y2, const vector<vector<char>> &image) {
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (image[i][j] == '1')
                    return true;
            }
        }
        return false;
    }

    int getLeft(int st, int ed, const int n, const vector<vector<char>> &image) {
        int ans = ed;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (doesContain(0, mid, n, mid, image)) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    int getRight(int st, int ed, const int n, const vector<vector<char>> &image) {
        int ans = ed;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (doesContain(0, mid, n, mid, image)) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }

    int getTop(int st, int ed, const int m, const vector<vector<char>> &image) {
        int ans = ed;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (doesContain(mid, 0, mid, m, image)) {
                ans = mid;
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    int getDown(int st, int ed, const int m, const vector<vector<char>> &image) {
        int ans = ed;
        while (st <= ed) {
            int mid = (st + ed) / 2;
            if (doesContain(mid, 0, mid, m, image)) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans;
    }



    int minArea(vector<vector<char>>& image, int x, int y) {
        int n = image.size();
        int m = image[0].size();
        int left = getLeft(0, y, n-1, image);
        int right = getRight(y, m-1, n-1, image);
        int top = getTop(0, x, m-1, image);
        int down = getDown(x, n-1, m-1, image);
        return (right - left + 1) * (down - top + 1);
    }
};
