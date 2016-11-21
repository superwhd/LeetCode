class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> slx;
        long long now = 0;
        for (auto num : nums) {
            now += num;
            slx.push_back(now);
        }
        slx.push_back(0);
        sort(begin(slx), end(slx));
        slx.erase(unique(begin(slx), end(slx)), end(slx));
        vector<int> tr(1 + slx.size());
        now = 0;
        auto add = [&] (int x) {
            for (; x && x <= slx.size(); x += x & -x) {
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
        auto find_lower = [&] (long long x) {
            return min(lower_bound(begin(slx), end(slx), x) - begin(slx), long(slx.size()));
        };
        auto find_upper = [&] (long long x) {
            return min(upper_bound(begin(slx), end(slx), x) - begin(slx), long(slx.size()));
        };
        auto find = [&] (long long x) {
            return lower_bound(begin(slx), end(slx), x) - begin(slx) + 1;
        };
        add(find(0));
        int ans = 0;
        for (auto num : nums) {
            now += num;
            // cout << slx[find_lower(now - upper) - 1] << " " << slx[find_upper(now - lower) - 1] << endl;
            ans += get(find_upper(now - lower)) - get(find_lower(now - upper));
            add(find(now));
            // cout << ans << endl;
        }
        return ans;
    }
};
