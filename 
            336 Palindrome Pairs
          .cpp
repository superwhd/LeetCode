class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        if (!words.size()) {
            return {};
        }
        set<vector<int>> ans;
        auto solve = [&] (vector<string> &a, bool rev) {
            int n = a.size();
            unordered_map<string, vector<int>> dic;
            for (int i = 0; i < n; i++) {
                auto tmp = a[i];
                reverse(begin(tmp), end(tmp));
                dic[tmp].push_back(i);
            }
            auto check = [] (const string &s) {
                for (int i = 0; i + i < s.size(); i++) {
                    if (s[i] != s[s.size() - i - 1]) {
                        return false;
                    }
                }
                return true;
            };
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= a[i].size(); j++) {
                    auto it = dic.find(a[i].substr(0, j));
                    if (it != end(dic)) {
                        if (check(a[i].substr(j, a[i].size() - j))) {
                            for (auto k : it->second) {
                                if (i == k) {
                                    continue;
                                }
                                if (!rev) {
                                    ans.insert({i, k});
                                } else {
                                    ans.insert({k, i});
                                }
                            }
                        }
                    }
                }
            }
        };
        solve(words, false);
        for (auto &word : words) {
            reverse(begin(word), end(word));
        }
        solve(words, true);
        vector<vector<int>> ansvec;
        for (auto &&vec : ans) {
            ansvec.emplace_back(vec);
        }
        return ansvec;
    }
    
};
