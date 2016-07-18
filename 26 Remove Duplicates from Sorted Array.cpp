class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!i || nums[i] != nums[k - 1]) {
                nums[k++] = nums[i];
            }
        }
        nums.erase(nums.begin() + k, nums.end());
        return k;
    }
};