class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long mx = 0;
        for (auto num : nums) {
            if (num <= mx + 1) {
                mx += num;
            } else {
                while (mx + 1 < n && mx + 1 < num) {
                    mx = mx * 2 + 1;
                    ans++;
                }
                if (num <= mx + 1) {
                    mx += num;
                }
            }
        }
        while (mx < n) {
            mx = mx * 2 + 1;
            ans++;
        }
        return ans;
    }
};
