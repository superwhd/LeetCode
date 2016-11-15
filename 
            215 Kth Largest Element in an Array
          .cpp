class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        nth_element(begin(nums), begin(nums) + k, end(nums));
        return nums[k];
    }
};
