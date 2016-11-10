class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int n = s.size();
        vector<int> next(n, -1);
        int j = -1;
        for (int i = 1; i < n; i++) {
            while (j != -1 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
        j = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (j != -1 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[i] == s[j + 1]) {
                j++;
            }
        }
        string ans;
        for (++j; j < n; j++) {
            ans += s[j];
        }
        reverse(begin(ans), end(ans));
        return ans + s;
    }
};
