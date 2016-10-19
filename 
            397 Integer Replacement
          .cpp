class Solution {
public:
    int integerReplacement(int n) {
        return dfs(n);
    }
private:
    int dfs(long long x) {
        if (x == 1)
            return 0;
        if (f.count(x)) {
            return f[x];
        }
        if (x & 1) {
            f[x] =  min(dfs(x - 1), dfs(x + 1)) + 1;
        } else {
            f[x] = dfs(x / 2) + 1;
        }
        return f[x];
    }
    map<long long, int> f;
};
