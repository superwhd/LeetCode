class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long nn = n;
        if (nn < 0) {
            nn = -nn;
            x = 1.0 / x;
        }
        for (; nn; nn >>= 1, x *= x)
            if (nn & 1)
                ans = ans * x;
        return ans;
    }
};