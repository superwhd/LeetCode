class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int n = prices.size();
        vector<array<int, 2>> f(n);
        for (int i = 0; i < n; i++) {
            f[i][0] = f[i][1] = 0;
            if (i) {
                f[i][0] = max(f[i][0], f[i - 1][0]);
                f[i][0] = max(f[i][0], f[i - 1][1]);
                f[i][1] = max(f[i][1], f[i - 1][1] + prices[i] - prices[i - 1]);
                f[i][1] = max(f[i][1], (i >= 2 ? f[i - 2][0] : 0) + prices[i] - prices[i - 1]);
            }
        }
        return max(f[n - 1][0], f[n - 1][1]);
    }
};
