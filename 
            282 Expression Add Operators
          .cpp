class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        function<void(int, string, long, long)> dfs = [&] (int dep, string path, long lhs, long rhs) {
            if (dep == num.size()) {
                if (lhs + rhs == target) {
                    ans.emplace_back(path);
                }
                return ;
            }
            for (int i = dep; i < num.size(); i++) {
                auto substr = num.substr(dep, i - dep + 1);
                if (substr.size() > 1 && substr[0] == '0') {
                    continue;
                }
                auto x = stol(substr);
                if (!dep) {
                    dfs(i + 1, path + substr, 0, x);
                } else {
                    dfs(i + 1, path + '*' + substr, lhs, rhs * x);
                    dfs(i + 1, path + '-' + substr, lhs + rhs, -x);
                    dfs(i + 1, path + '+' + substr, lhs + rhs, x);
                }
            }
        };
        dfs(0, "", 0, 0);
        return ans;
    }
};
