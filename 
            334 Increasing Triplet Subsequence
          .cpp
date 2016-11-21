class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> res{0x7fffffff, 0x7fffffff};
        for (int i = 0; i < nums.size(); i++) {
            int j;
            for (j = 0; j < res.size(); j++) {
                if (res[j] >= nums[i]) {
                    break;
                }
            }
            if (j == 2) {
                return true;
            }
            res[j] = nums[i];
        }
        return false;
    }
};
