class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> slx(nums);
        sort(begin(slx), end(slx));
        vector<int> tr(slx.size() + 1);
        auto add = [&] (int x) {
            for (; x && x < tr.size(); x += x & -x) {
                tr[x]++;
            }
        };
        auto get = [&] (int x) {
            int s = 0;
            for (; x; x -= x & -x) {
                s += tr[x];
            }
            return s;
        };
        vector<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int pos = lower_bound(begin(slx), end(slx), nums[i]) - begin(slx) + 1;
            ans[i] = get(pos - 1);
            add(pos);
        }
        return ans;
    }
};
