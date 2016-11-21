class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> s(nums);
        for (int i = 1; i < nums.size(); i++) {
            s[i] = s[i - 1] * s[i];
            if (s[i] == 0) {
                s[i] = 1;
            }
        }
        auto subArrayProduct = [&] (int l, int r) {
            if (l > r) {
                return -0x7fffffff - 1;
            }
            return s[r] / s[l] * nums[l];
        };
        int ans = nums[0];
        auto maxSubArrayProduct = [&] (int l, int r) {
            if (l > r) {
                return ;
            }
            int nega = 0;
            for (int i = l; i <= r; i++) {
                nega += nums[i] < 0;
            }
            if (nega % 2 == 0) {
                ans = max(ans, subArrayProduct(l, r));
                return ;
            }
            int res = nums[l];
            for (int i = l; i <= r; i++) {
                if (nums[i] < 0) {
                    res = max(res, subArrayProduct(i + 1, r));
                    break;
                }
            }
            for (int i = r; i >= l; i--) {
                if (nums[i] < 0) {
                    res = max(res, subArrayProduct(l, i - 1));
                    break;
                }
            }
            ans = max(ans, res);
        };
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                int j;
                for (j = i; j < nums.size() && nums[j]; j++);
                j--;
                maxSubArrayProduct(i, j);
                i = j;
            } else {
                ans = max(ans, 0);
            }
        }
        return ans;
    }
};
