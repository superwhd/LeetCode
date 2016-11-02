class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty()) {
            return vector<string>();
        }
        struct Node {
            Node() {
                id = -1;
            }
            shared_ptr<Node> c[26];
            int id;
        };
        using NodePtr = shared_ptr<Node>;
        NodePtr root(new Node());
        auto insert = [&] (const string &s, int id) {
            NodePtr now = root;
            for (auto c : s) {
                c = c - 'a';
                if (!now->c[c]) {
                    now->c[c] = NodePtr(new Node());
                }
                now = now->c[c];
            }  
            now->id = id;
        };
        for (int i = 0; i < words.size(); i++) {
            insert(words[i], i);
        }
        unordered_set<int> res_ids;
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        function<void(int, int, NodePtr)> dfs = [&] (int x, int y, NodePtr now) {
            vis[x][y] = true;
            if (now->id != -1) {
                res_ids.insert(now->id);
            }  
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (0 <= xx && xx < n && 0 <= yy && yy < m && !vis[xx][yy]) {
                    auto c = board[xx][yy] - 'a';
                    if (now->c[c]) {
                        dfs(xx, yy, now->c[c]);
                    }
                }
            }
            vis[x][y] = false;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto c = board[i][j] - 'a';
                if (root->c[c]) {
                    dfs(i, j, root->c[c]);
                }
            }
        }
        vector<string> ans;
        for (auto id : res_ids) {
            ans.push_back(words[id]);
        }
        return ans;
    }
};
