class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int tmp = 1;
        for (int i = 0; i < nums.size(); i++) {
            tmp *= nums[i];
            ans[i] = tmp;
        }
        tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = tmp * (i ? ans[i - 1] : 1);
            tmp *= nums[i];
        }
        return ans;
    }
};