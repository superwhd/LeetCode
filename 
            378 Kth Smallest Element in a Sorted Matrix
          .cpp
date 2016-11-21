class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = matrix[0][0], r = matrix[0][0];
        for (auto &row : matrix) {
            for (auto num : row) {
                l = min(l, num);
                r = max(r, num);
            }
        }
        auto rank = [&] (int row, int x) {
            return upper_bound(begin(matrix[row]), end(matrix[row]), x) - begin(matrix[row]);
        };
        auto get = [&] (int x) {
            int s = 0;
            for (int i = 0; i < n; i++) {
                s += rank(i, x);
            }
            return s;
        };
        while (l <= r) {
            int mid = (0ll + l + r) >> 1;
            if (get(mid) >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
