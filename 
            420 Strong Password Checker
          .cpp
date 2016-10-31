class Solution {
public:
    int strongPasswordChecker(string s) {
        const int inf = 0x3f3f3f3f;
        auto n = s.size();
        const int charset = 2 + 2 + 2;
        vector<vector<vector<vector<vector<int>>>>> f(s.size() + 1, vector<vector<vector<vector<int>>>>(21, vector<vector
            <vector<int>>>(charset, vector<vector<int>>(3, vector<int>(8, inf)))));
        // int f[100][21][charset][3][1 << 3];
        // memset(f, inf, sizeof(f));
        f[0][0][0][0][0] = 0;
        for (auto &ch : s) {
            if (isdigit(ch)) {
                ch -= '0';
            } else if (isupper(ch)) {
                ch -= 'A';
                ch += 10;
            } else {
                ch -= 'a';
                ch += 36;
            }
        }
        char last = s[0];
        for (int i = 0; i < s.size(); i++) {
            bool dif = (i && s[i] != last);
            int lastv = i ? s[i - 1] : 0;
            last = s[i];
            if (s[i] < 10) {
                s[i] = 0 ^ (dif ^ (lastv & 1));
            } else if (s[i] < 36) {
                s[i] = 2 ^ (dif ^ (lastv & 1));
            } else {
                s[i] = 4 ^ (dif ^ (lastv & 1));
            }
            // cout << int(s[i]) << endl;
        }
        auto type = [] (char x) {
            if (x < 2) {
                return 1 << 0;
            } else if (x < 4) {
                return 1 << 1;
            } else {
                return 1 << 2;
            }
        };
        for (int len = 0; len < 20; len++) {
            for (int i = 0; i <= n; i++) {
                for (int lastchar = 0; lastchar < charset; lastchar++) {
                    for (int repeat = 0; repeat < 3; repeat++) {
                        for (int state = 0; state < 8; state++) {
                            if (f[i][len][lastchar][repeat][state] >= inf) {
                                continue;
                            }
                            int x = f[i][len][lastchar][repeat][state];
                            // keep
                            if (i < n) {
                                {
                                    char ch = s[i];
                                    if (repeat < 2 || lastchar != ch) {
                                        int &y = f[i + 1][len + 1][ch][lastchar == ch ? repeat + 1 : 1][state | type(ch)];
                                        y = min(x, y);
                                    }
                                }
                                // remove
                                {
                                    int &y = f[i + 1][len][lastchar][repeat][state];
                                    y = min(y, x + 1);
                                }
                            }
                            // add or change
                            {
                                for (int ch = 0; ch < charset; ch++) {
                                    if (repeat < 2 || lastchar != ch) {
                                        {
                                            int &y = f[i][len + 1][ch][lastchar == ch ? repeat + 1 : 1][state | type(ch)];
                                            y = min(y, x + 1);
                                        }
                                        if (i < n) {
                                            int &y = f[i + 1][len + 1][ch][lastchar == ch ? repeat + 1 : 1][state | type(ch)]
                                                ;
                                            y = min(y, x + 1);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = inf;
        for (int len = 6; len <= 20; len++) {
            for (int ch = 0; ch < charset; ch++) {
                for (int repeat = 0; repeat < 3; repeat++) {
                    ans = min(ans, f[s.size()][len][ch][repeat][7]);
                }
            }
        }
        return ans;
    }
};
