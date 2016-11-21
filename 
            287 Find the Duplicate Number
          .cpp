class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0, n = nums.size() - 1;
        for (int bit = 0; bit < 31; bit++) {
            int cntOriginal = 0, cntNums = 0;
            for (int i = 1; i <= n; i++) {
                cntOriginal += i >> bit & 1;
            }
            for (auto num : nums) {
                cntNums += num >> bit & 1;
            }
            ans += (cntNums > cntOriginal) << bit;
        }
        return ans;
    }
};
