class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        function<int(int, int)> calc = [&] (int l, int r) {
            if (l == r) {
                return l;
            }
            if (nums[l] > nums[l + 1]) {
                return l;
            }
            if (nums[r - 1] < nums[r]) {
                return r;
            }
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid + 1]) {
                return calc(l, mid);
            } else {
                return calc(mid + 1, r);
            }
        };
        return calc(0, nums.size() - 1);
    }
};
