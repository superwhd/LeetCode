class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (!s.size()) {
            return 0;
        }
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int j = 0;
        int ans = 0;
        for (int i = 0; i < g.size(); i++) {
            while (j < s.size() && s[j] < g[i]) {
                j++;
            }
            if (j < s.size() && s[j] >= g[i]) {
                j++;
                ans++;
            }
        }
        return ans;
    }
};
