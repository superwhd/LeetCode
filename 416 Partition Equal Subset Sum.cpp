class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        auto &a = nums;
        int n = a.size(), m = sum;
        if (sum % 2)
            return false;
        vector<int> f(m + 1);
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = m / 2; j >= a[i]; j--)
                f[j] |= f[j - a[i]];
        }
        return f[m / 2];
    }
};
