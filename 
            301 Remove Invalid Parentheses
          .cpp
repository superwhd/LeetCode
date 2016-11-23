class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int cL = 0, cR = 0;
        for (auto ch : s) {
            if (ch == '(') {
                cL++;
            } else if (ch == ')') {
                if (cL) {
                    cL--;
                } else {
                    cR++;
                }
            }
        }
        function<void(int, int, int, vector<int> &)> dfs = [&] (int dep, int cL, int cR, vector<int> &del) {
            if (!cL && !cR) {
                string tmp;
                int j = 0;
                for (int i = 0; i < s.size(); i++) {
                    while (j < del.size() && del[j] < i) {
                        j++;
                    }
                    if (j == del.size() || i != del[j]) {
                        tmp.push_back(s[i]);
                    }
                }
                auto sum = 0;
                for (auto ch : tmp) {
                    if (ch == '(') {
                        sum++;
                    } else if (ch == ')') {
                        sum--;
                    }
                    if (sum < 0) {
                        return ;
                    }
                }
                ans.push_back(tmp);
                return ;
            }  
            for (int i = dep; i < s.size(); i++) {
                if (s[i] == '(') {
                    if (cL && !cR) {
                        del.push_back(i);
                        dfs(i + 1, cL - 1, cR, del);
                        del.pop_back();
                    }
                } else if (s[i] == ')') {
                    if (cR) {
                        del.push_back(i);
                        dfs(i + 1, cL, cR - 1, del);
                        del.pop_back();
                    }
                }
            }
        };
        vector<int> delTmp;
        dfs(0, cL, cR, delTmp);
        sort(begin(ans), end(ans));
        ans.erase(unique(begin(ans), end(ans)), end(ans));
        return ans;
    }
};
