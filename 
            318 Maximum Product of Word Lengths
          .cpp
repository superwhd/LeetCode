class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int, int>> a;
        for (auto word : words) {
            int state = 0;
            for (auto c : word) {
                state |= 1 << (c - 'a');
            }
            a.emplace_back(state, word.size());
        }
        int ans = 0;
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (!(a[i].first & a[j].first)) {
                    ans = max(ans, a[i].second * a[j].second);
                }
            }
        }
        return ans;
    }
};
