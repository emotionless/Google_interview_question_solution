class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>> &visited) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int ax = x + dr[i];
            int ay = y + dc[i];
            if (ax < 0 || ax >= n || ay < 0 || ay >= m || grid[ax][ay] == '0' || visited[ax][ay]) continue;
            dfs(ax, ay, grid, visited);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, grid, visited);
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    int n, m;
};