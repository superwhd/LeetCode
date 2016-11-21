class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> q(nums.size());
        int top = 0;
        for (auto num : nums) {
            int l = 0, r = top - 1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (q[mid] < num) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            q[r + 1] = num;
            if (r + 1 == top) {
                top++;
            }
        }
        return top;
    }
};
