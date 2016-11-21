class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size()) {
            return 0;
        }
        vector<vector<int>> dis(matrix), d(matrix);
        int n = matrix.size(), m = matrix[0].size();
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        auto in = [&] (int x, int y) {
            return 0 <= x && x < n && 0 <= y && y < m;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dis[i][j] = 0;
                d[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (in(x, y) && matrix[i][j] > matrix[x][y]) {
                        d[i][j]++;
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!d[i][j]) {
                    q.emplace(i, j);
                    dis[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            auto s = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                auto v = s;
                v.first += dx[k];
                v.second += dy[k];
                if (in(v.first, v.second) && matrix[s.first][s.second] < matrix[v.first][v.second]) {
                    dis[v.first][v.second] = max(dis[v.first][v.second], dis[s.first][s.second] + 1);
                    if (!--d[v.first][v.second]) {
                        q.emplace(v.first, v.second);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dis[i][j]);
            }
        }
        return ans;
    }
};
