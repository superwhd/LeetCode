class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(begin(nums), end(nums));
        int mid = nums[nums.size() / 2];
        int ans = 0;
        for (auto num : nums) {
            ans += abs(num - mid);
        }
        return ans;
    }
};
