class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        for (int j = 1; j + 1 < nums.size(); j++) {
            int k = j + 1;
            for (int i = j - 1; i >= 0; i--) {
                int sumij = nums[i] + nums[j];
                while (k < nums.size() && sumij + nums[k] <= target)
                    k++;
                if (k < nums.size() && abs(target - ans) > abs(target - (sumij + nums[k])))
                    ans = sumij + nums[k];
                if (k > j + 1) {
                    k--;  
                    if (k < nums.size() && abs(target - ans) > abs(target - (sumij + nums[k])))
                        ans = sumij + nums[k];
                }
            }
        }
        return ans;
    }
};