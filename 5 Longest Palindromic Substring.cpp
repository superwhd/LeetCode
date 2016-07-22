class Solution {
public:
    string longestPalindrome(string s) {
        int ansl = 0, ansr = 0;
        for (int i = 0; i < s.size(); i++) {
            int l, r;
            for (l = i, r = l + 1; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++);
            l++;
            r--;
            if (r - l + 1 > ansr - ansl) {
                ansl = l;
                ansr = r;
            }
            for (l = i, r = l; l >= 0 && r < s.size() && s[l] == s[r]; l--, r++);
            l++;
            r--;
            if (r - l + 1 > ansr - ansl) {
                ansl = l;
                ansr = r;
            }
        }
        return s.substr(ansl, ansr - ansl + 1);
    }
};