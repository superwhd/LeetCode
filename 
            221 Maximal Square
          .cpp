class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (!matrix.size()) {
            return 0;
        }
        auto &a = matrix;
        int n = a.size(), m = a[0].size();
        int ans = 0;
        vector<vector<int>> f(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    f[i][j] = 1;
                    if (i && j) {
                        f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]);
                        f[i][j] = min(f[i][j], f[i][j - 1]);
                        f[i][j]++;
                    }
                    ans = max(ans, f[i][j]);
                }
            }
        }
        return ans * ans;
    }
};
