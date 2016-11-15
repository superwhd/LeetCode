class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (isdigit(c)) {
                int num = 0;
                int j;
                for (j = i; j < input.size() && isdigit(input[j]); j++) {
                    num *= 10;
                    num += input[j] - '0';
                }
                nums.push_back(num);
                i = j - 1;
            } else {
                ops.push_back(c);
            }
        }
        auto calc = [] (int x, char op, int y) {
            switch(op) {
                case '+':
                    return x + y;
                case '-':
                    return x - y;
                case '*':
                    return x * y;
            }
            return 0;
        };
        auto n = nums.size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(n));
        function<void(int, int)> dfs = [&] (int l, int r) {
            auto &res = f[l][r];
            if (res.size()) {
                return ;
            }
            if (l == r) {
                res = vector<int>{nums[l]};
                return ;
            }
            for (int i = l; i < r; i++) {
                dfs(l, i);
                dfs(i + 1, r);
                auto &left = f[l][i], &right = f[i + 1][r];
                for (auto leftres : left) {
                    for (auto rightres : right) {
                        res.push_back(calc(leftres, ops[i], rightres));
                    }
                }
            }
            return ;
        };
        dfs(0, n - 1);
        return f[0][n - 1];
    }
};
