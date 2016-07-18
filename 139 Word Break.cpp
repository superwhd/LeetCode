class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> f(s.size() + 1);
        f[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (auto &word : wordDict) {
                if (i >= word.size() && f[i - word.size()] && word == s.substr(i - word.size(), word.size()))
                    f[i] = true;
            }
        }
        return f[s.size()];
    }
};