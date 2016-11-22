class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (0 < nums[i] && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        int i;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                break;
            }
        }
        return i + 1;
    }
};
