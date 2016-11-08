class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_multiset<int> f;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k + 1) {
                f.erase(nums[i - k - 1]);
            }
            if (f.count(nums[i])) {
                return true;
            }
            f.insert(nums[i]);
        }
        return false;
    }
};
