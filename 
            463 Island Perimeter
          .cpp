class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        vector<vector<int>> vis = grid;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }
        int ans = 0;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        function<void(int, int)> dfs = [&] (int x, int y) {
            if (!grid[x][y]) {
                return ;
            }  
            vis[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (0 <= xx && xx < n && 0 <= yy && yy < m && grid[xx][yy]) {
                    if (!vis[xx][yy]) {
                        dfs(xx, yy);
                    }
                } else {
                    ans++;
                }
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    dfs(i, j);
                }
            }
        }    
        return ans;
    }
};
