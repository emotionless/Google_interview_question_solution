/*

Problem link: https://leetcode.com/problems/number-of-distinct-islands/

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011
Given the above grid map, return 3.

Notice that:
11
1
and
 1
11
are considered different island shapes, because we do not consider reflection / rotation.
Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution
{
public:

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    char ch[4] = {'U', 'R', 'D', 'L'};

    string getSequence(int x, int y, vector<vector<int>> &grid)
    {
        string ret = "";
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++)
        {
            int ax = x + dr[i];
            int ay = y + dc[i];
            if (ax < 0 || ax >= n || ay < 0 || ay >= m || grid[ax][ay] == 0) continue;
            string cur = getSequence(ax, ay, grid);
            ret = ret + ch[i] + cur;
        }
        ret += "E";
        return ret;
    }

    int numDistinctIslands(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        unordered_map<string, bool> vis;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    string seq = getSequence(i, j, grid);
                    if (vis.find(seq) == vis.end())
                    {
                        vis[seq] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
private:
    int n, m;
};

/*

[[1,1,0],
[0,1,1],
[0,0,0],
[1,1,1],
[0,1,0]]



*/
