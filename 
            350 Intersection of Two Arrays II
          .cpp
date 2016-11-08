class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        int i = 0, j = 0;
        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            int x = nums1[i], y = nums2[j];
            if (x == y) {
                res.push_back(x);
                i++;
                j++;
            } else if (x < y) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
