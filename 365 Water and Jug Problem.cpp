class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (!x && !y)
            return !z;
        if (z > x + y)
            return false;
        return z % __gcd(x, y) == 0;
    }
};