class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> f(nums.size() + 1);
        f[0] = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            f[i + 1] = f[i];
            f[i + 1] = max(f[i + 1], (i ? f[i - 1] : 0) + nums[i]);
            ans = max(ans, f[i + 1]);
        }
        return ans;
    }
};