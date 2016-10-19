class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        auto &a = matrix;
        auto rows = vector<vector<int>>(n, vector<int>(m, 0));
        int ans = 0;
        bool visAns = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rows[i][j] = a[i][j];
                if (j) {
                    rows[i][j] += rows[i][j - 1];
                }
            }
        }
        auto getRowSum = [&] (int x, int l, int r) -> int {return rows[x][r] - rows[x][l] + a[x][l];};
        for (int l = 0; l < m; l++) {
            for (int r = l; r < m; r++) {
                int s = 0;
                multiset<int> f;
                f.insert(0);
                for (int i = 0; i < n; i++) {
                    s += getRowSum(i, l, r);
                    auto it = f.lower_bound(s - k);
                    if (it != f.end()) {
                        if (ans < s - *it || !visAns) {
                            visAns = true;
                            ans = s - *it;
                        }
                    }
                    f.insert(s);
                }
            }
        }
        return ans;
    }
};
