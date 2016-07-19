class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> f(num + 1);
        for (int i = 1; i <= num; i++)
            f[i] = (i & 1) ? f[i >> 1] + 1 : f[i >> 1];
        return f;
    }
};