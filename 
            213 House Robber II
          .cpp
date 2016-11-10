class Solution {
public:
    int rob(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        int n = nums.size();
        int x = nums[0];
        if (n == 1) {
            return max(x, 0);
        }
        const int inf = -0x3f3f3f3f;
        int k = 0;
        int ans = 0;
        for (int t : {0, x}) {
            nums[0] = t;
            vector<vector<int>> f(n, vector<int>(2, -inf));
            f[0][0] = 0;
            f[0][1] = nums[0];
            for (int i = 1; i < n; i++) {
                f[i][0] = max(f[i - 1][0], f[i - 1][1]);
                f[i][1] = f[i - 1][0] + nums[i];
            }
            if (!k) {
                k++;
                ans = max(ans, f[n - 1][1]);
            }
            ans = max(ans, f[n - 1][0]);
        }
        return ans;
    }
};
