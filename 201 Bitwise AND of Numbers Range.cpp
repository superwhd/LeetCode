class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            int mask = (1ll << (i + 1)) - 1;
            int rest = m ^ (m & mask);
            long long next = rest + (1ll << (i + 1));
            if (m >> i & 1 && next > n)
                ans += 1 << i;
        }
        return ans;
    }
};