class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = nums[0];
        for (auto num : nums) {
            mn = min(mn, num);
        }
        int ans= 0;
        for (auto num : nums) {
            ans += num - mn;
        }
        return ans;
    }
};
