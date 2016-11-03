class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) {
            return ;
        }
        vector<vector<int>> ans = board;
        auto n = board.size(), m = board[0].size();
        auto countNeighbor = [&] (int x, int y) {
            int res = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i || j) {
                        int xx = x + i, yy = y + j;
                        if (0 <= xx && xx < n && 0 <= yy && yy < m) {
                            res += !!board[xx][yy];
                        }
                    }
                }
            }
            return res;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto s = countNeighbor(i, j);                    
                auto &res = ans[i][j];
                if (board[i][j]) {
                    if (s < 2 || s > 3) {
                        res = 0;
                    } 
                } else {
                    if (s == 3) {
                        res = 1;
                    }
                }
            }
        }
        board = move(ans);
    }
};
