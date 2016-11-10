class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if (!nums.size()) {
            return {};
        }
        int n = nums.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n), pre(n, -1), f(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && nums[i] % nums[j] == 0) {
                    adj[j].push_back(i);
                    ind[i]++;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!ind[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int s = q.front();
            q.pop();
            for (auto v : adj[s]) {
                if (f[v] < f[s] + 1) {
                    f[v] = f[s] + 1;
                    pre[v] = s;
                }
                if (!--ind[v]) {
                    q.push(v);
                }
            }
        }
        int last = 0;
        for (int i = 0; i < n; i++) {
            if (f[last] < f[i]) {
                last = i;
            }
        }
        for (; last != -1; last = pre[last]) {
            ans.push_back(nums[last]);
        }
        return ans;
    }
};
