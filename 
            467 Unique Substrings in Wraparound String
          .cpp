class Solution {
public:
    int findSubstringInWraproundString(string p) {
        string s = "", tmp = "abcdefghijklmnopqrstuvwxyz";
        s += tmp;
        s += tmp;
        // while (s.size() < tmp.size() + p.size()) {
        //     s += tmp;
        // }
        unordered_set<string> dic;
        auto ck = [&] (const string &x) {
            return s.find(x) != string::npos;
        };
        int ans = 0, mxcnt = 0;
        unordered_map<char, int> f;
        int lastcnt = 0;
        for (int i = 0; i < p.size(); i++) {
            int cnt = max(lastcnt - 1, 0);
            int mv = p[i] - 'a';
            for (int j = i + cnt; j < p.size(); j++) {
                if (p[j] != ('a' + (mv + cnt) % 26)) {
                    break;
                }
                cnt++;
            }
            if (cnt >= lastcnt) {
                for (int j = i; j < i + min(cnt, 26); j++) {
                    f[p[j]] = max(f[p[j]], cnt - j + i);
                }
            }
            lastcnt = cnt;
            mxcnt = max(mxcnt, cnt);
        }
        // cout << mxcnt << endl;
        // if (mxcnt > 26) {
        //     for (int i = 27; i <= mxcnt; i++) {
        //         ans += min(26, mxcnt - i + 1);
        //     }
        // }
        // for (int i = 0; i < p.size(); i++) {
        //     string now;
        //     for (int j = i; j < p.size() && j < i + 26; j++) {
        //         now += p[j];
        //         // cout << now << " " << dic.count(now) << endl;
        //         if (!dic.count(now)) {
        //             dic.insert(now);
        //             if (ck(now)) {
        //                 ans++;
        //             }
        //         }
        //     }
        // }
        for (int i = 'a'; i <= 'z'; i++) {
            // if (f[i] > 26) {
                ans += (f[i]);
            // }
        }
        return ans;
    }
};
