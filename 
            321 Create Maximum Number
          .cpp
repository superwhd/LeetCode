class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        auto get = [&] (vector<int> &nums, int m) {
            int n = nums.size();
            vector<int> res;
            for (int i = 0; i < n && res.size() < m; i++) {
                int mx = -1;
                int mxj = nums.size() - (m - res.size() - 1);
                int j;
                for (j = i; j < mxj; j++) {
                    mx = max(mx, nums[j]); 
                }
                for (j = i; j < mxj; j++) {
                    if (nums[j] == mx) {
                        break;
                    }
                }
                res.push_back(mx);
                i = j;
            }
            return res;
        };
        auto solve = [&] (vector<int> &a, vector<int> &b) {
            int n = a.size(), m = b.size();
            int i = 0, j = 0;
            vector<int> res;
            while (i < n || j < m) {
                if (i < n && j < m) {
                    int k;
                    for (k = 0; i + k < n && j + k < m; k++) {
                        if (a[i + k] != b[j + k]) {
                            break;
                        }
                    }
                    if (i + k == n) {
                        res.push_back(b[j++]);
                    } else if (j + k == m) {
                        res.push_back(a[i++]);
                    } else {
                        if (a[i + k] > b[j + k]) {
                            res.push_back(a[i++]);
                        } else {
                            res.push_back(b[j++]);
                        }
                    }
                } else if (i < n) {
                    res.push_back(a[i++]);
                } else if (j < m) {
                    res.push_back(b[j++]);
                }
            }
            return res;
        };
        vector<int> ans;
        for (int l1 = 0; l1 <= nums1.size(); l1++) {
            int l2 = k - l1;
            if (0 <= l2 && l2 <= nums2.size()) {
                auto v1 = get(nums1, l1);
                auto v2 = get(nums2, l2);
                auto res = solve(v1, v2);
                ans = max(ans, res);
            }
        }
        return ans;
    }
};
