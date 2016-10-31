class Solution {
public:
    int arrangeCoins(int n) {
        int r = 1;
        while (n >= r) {
            n -= r;
            r++;
        }
        return r - 1;
    }
};
