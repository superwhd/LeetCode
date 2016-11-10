class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for (auto &e : prerequisites) {
            auto y = e.first, x = e.second;
            adj[x].push_back(y);
            in[y]++;
        }
        vector<int> ans;
        function<void(int)> dfs = [&] (int x) {
            in[x] = -1;
            ans.push_back(x);
            for (auto t : adj[x]) {
                if (!--in[t]) {
                    dfs(t);
                }
            }  
        };
        for (int i = 0; i < n; i++) {
            if (!in[i]) {
                dfs(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (in[i] != -1) {
                return {};
            }
        }
        return ans;
    }
};
