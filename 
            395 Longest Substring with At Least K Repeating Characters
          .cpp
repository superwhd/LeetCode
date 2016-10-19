class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> cnt(26, 0);
        int ans = 0;
        for (int c = 1; c <= 26; c++) {
            int i = 0, j = 0, now = 0, dif = 0;
            fill(cnt.begin(), cnt.end(), 0);
            while (j < s.size()) {
                auto x = s[j] - 'a';
                if (dif <= c) {
                    cnt[x]++;
                    if (cnt[x] == 1) {
                        dif++;
                    }
                    if (cnt[x] == k) {
                        now++;
                    }
                    j++;
                } else {
                    auto y = s[i] - 'a';
                    cnt[y]--;
                    if (!cnt[y]) {
                        dif--;
                    }
                    if (cnt[y] == k - 1) {
                        now--;
                    }
                    i++;
                }
                if (now == c && dif == c) {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
};
