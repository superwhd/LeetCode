class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        struct Node {
            Node *l, *r, *u, *d;
            int row, col;
        };
        // for (int i = 0; i < 9; i++, cout << endl) {
        //     for (int j = 0; j < 9; j++) {
        //         cout << board[i][j];
        //     }
        // }
        const int ROWS = 9 * 9 * 9, COLS = 9 * 9 * 4;
        vector<Node> mem(1 + COLS + 4 * ROWS);
        vector<int> cnt(COLS);
        vector<Node *> heads(COLS);
        int top = 0;
        auto newNode = [&] (int row, int col) {
            auto res = &mem[top++];
            res->row = row;
            res->col = col;
            res->l = res->r = res->u = res->d = nullptr;
            return res;
        };
        for (int i = 0; i < heads.size(); i++) {
            heads[i] = newNode(-1, i);
            heads[i]->d = heads[i]->u = heads[i];
            cnt[i] = 0;
        }
        vector<int> visR(9), visC(9), visG(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    auto num = board[i][j] - '1';
                    visR[i] |= 1 << num;
                    visC[j] |= 1 << num;
                    visG[(i / 3) * 3 + j / 3] |= 1 << num;
                }
            }
        }
        auto addRow = [&] (int row) {
            int x = row / (9 * 9), y = row / 9 % 9, z = row % 9;
            int col1 = x * 9 + z;
            int col2 = y * 9 + z + 9 * 9;
            int col3 = ((x / 3 * 3) + y / 3) * 9 + z + 9 * 9 * 2;
            int col4 = x * 9 + y + 9 * 9 * 3;
            vector<int> vec{col1, col2, col3, col4};
            Node *last = nullptr, *first = nullptr;
            for (auto col : vec) {
                auto node = newNode(row, col);
                if (!first) {
                    first = node;
                }
                node->u = heads[col]->u;
                node->u->d = node;
                node->d = heads[col];
                node->d->u = node;
                if (last) {
                    last->r = node;
                    node->l = last;
                }
                cnt[col]++;
                last = node;
            }
            last->r = first;
            first->l = last;
        };
        Node *root = newNode(-1, -1);
        root->l = root->r = root;
        for (auto head : heads) {
            head->l = root->l;
            head->r = root;
            head->r->l = head;
            head->l->r = head;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int state = 0;
                    state |= visR[i];
                    state |= visC[j];
                    state |= visG[(i / 3) * 3 + j / 3];
                    state ^= (1 << 9) - 1;
                    for (int k = 0; k < 9; k++) {
                        if ((state >> k) & 1) {
                            addRow(i * 9 * 9 + j * 9 + k);
                        }
                    }
                } else {
                    // addRow(i * 9 * 9 + j * 9 + board[i][j] - '1');
                }
            }
        }
        for (auto head : heads) {
            if (!cnt[head->col]) {
                head->l->r = head->r;
                head->r->l = head->l;
            }
        }
        auto delCol = [&] (int col) {
            for (auto i = heads[col]->d; i != heads[col]; i = i->d) {
                for (auto j = i->r; j != i; j = j->r) {
                    j->u->d = j->d;
                    j->d->u = j->u;
                    cnt[j->col]--;
                }
            }
            heads[col]->l->r = heads[col]->r;
            heads[col]->r->l = heads[col]->l;
        };
        auto recCol = [&] (int col) {
            for (auto i = heads[col]->d; i != heads[col]; i = i->d) {
                for (auto j = i->r; j != i; j = j->r) {
                    j->u->d = j;
                    j->d->u = j;
                    cnt[j->col]++;
                }
            }
            heads[col]->l->r = heads[col];
            heads[col]->r->l = heads[col];
        };
        bool flag = false;
        function<bool()> dfs = [&] () {
            if (root->r == root) {
                return true;
            }
            int minCol = root->r->col;
            for (auto now = root->r; now != root; now = now->r) {
                // cout << cnt[now->col] << ",";
                if (cnt[now->col] < cnt[minCol]) {
                    minCol = now->col;
                }
            }
            // cout << endl;
            delCol(minCol);
            for (auto i = heads[minCol]->d; i != heads[minCol]; i = i->d) {
                for (auto j = i->r; j != i; j = j->r) {
                    delCol(j->col);
                }
                int row = i->row;
                int x = row / (9 * 9), y = row / 9 % 9, z = row % 9;
                board[x][y] = z + '1';
                if (dfs()) {
                    return true;
                }
                for (auto j = i->r; j != i; j = j->r) {
                    recCol(j->col);
                }
            }
            recCol(minCol);
            flag = true;
            return false;
        };
        if (!dfs()) {
        }
        for (int i = 0; i < 9; i++, cout << endl) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
        }
    }
};
