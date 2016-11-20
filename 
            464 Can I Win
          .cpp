class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int n = maxChoosableInteger, m = desiredTotal;
        if (!m) {
            return true;
        }
        vector<int> f(1 << n, -1);
        int all = 1 << n, full = all - 1;

        auto calc = [&] (int state) {
            int s = 0;
            for (int i = 0; i < n; i++) {
                if (state >> i & 1) {
                    s += i + 1;
                }
            }
            return s;
        };
        if (calc(full) < m) {
            return false;
        }
        function<int(int)> dfs = [&] (int state) {
            int &x = f[state];
            if (x != -1) {
                return x;
            }
            if (calc(state) >= m) {
                return x = 0;
            }  
            x = 0;
            for (int i = 0; i < n; i++) {
                if (!(state >> i & 1)) {
                    if (!dfs(state | (1 << i))) {
                        return x = 1;
                    }
                }
            }
            return x;
        };
        return dfs(0);
    }
};
