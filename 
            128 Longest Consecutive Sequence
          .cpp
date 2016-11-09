class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 1;
        unordered_map<int, int> fa, s;
        for (auto num : nums) {
            fa[num] = num;
            s[num] = 1;
            ans = 1;
        }
        function<int(int)> gf = [&] (int x) {
            if (fa[x] != x) {
                fa[x] = gf(fa[x]);
            }  
            return fa[x];
        };
        for (auto num : nums) {
            if (fa.count(num - 1)) {
                int x = gf(num - 1), y = gf(num);
                if (x == y) {
                    continue;
                }
                fa[x] = y;
                s[y] += s[x];
                ans = max(ans, s[y]);
            }
        }
        return ans;
    }
};
