class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        s.resize(matrix.size() + 1);
        for (int i = 0; i <= matrix.size(); i++) {
            s[i].resize(matrix.size() ? matrix[0].size() + 1 : 1);
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s[i].size(); j++) {
                s[i][j] = 0;
                if (i && j) {
                    s[i][j] += matrix[i - 1][j - 1];
                    s[i][j] -= s[i - 1][j - 1];
                }
                if (i) {
                    s[i][j] += s[i - 1][j];
                }
                if (j) {
                    s[i][j] += s[i][j - 1];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2 + 1][col2 + 1] - s[row2 + 1][col1] -s[row1][col2 + 1] + s[row1][col1];
    }
private:
    vector<vector<int>> s;
};
// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);