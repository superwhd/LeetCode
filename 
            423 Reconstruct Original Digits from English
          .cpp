
class Solution {
public:
    string originalDigits(string s) {
        only.resize(10);
        for (int i = 0; i < 10; i++) {
            auto now = arr[order[i]];
            for (char c : now) {
                bool flag = true;
                for (int j = i + 1; j < 10; j++) {
                    for (char cc : arr[order[j]])
                        flag &= !(c == cc);
                }
                if (flag)
                    only[i].push_back(c);
            }
        }
        for (char c : s) {
            cnt[c - 'a'] ++;
        }
        ans.resize(s.size());
        dfs(0);
        string res;
        for (int i = 0; i < n; i++) {
            res.push_back(ans[i]);
        }
        sort(res.begin(), res.end());
        return res;
    }
    bool dfs(int dep) {
        if (dep == 10) {
            for (int i = 'a'; i <= 'z'; i++)
                if (cnt[i - 'a']) {
                    return false;
                }
            return true;
        }
        int i = 0;
        while (true) {
            bool godfs = true;
            for (char c : only[dep]) {
                if (cnt[c - 'a'])
                    godfs = false;
            }
            if (godfs && dfs(dep + 1))
                return true;            
            bool flag = true;
            for (auto c : arr[order[dep]]) {
                if (!cnt[c - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
            for (auto c : arr[order[dep]]) {
                cnt[c - 'a']--;
            }
            ans[n++] = '0' + order[dep];
            i++;
        }
        for (auto c : arr[order[dep]]) {
                cnt[c - 'a'] += i;
        }
        n -= i;
        return false;
    }
    int n = 0;
    vector<vector<char> > only;
    vector<char> ans;
    int cnt[29];
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int order[10] = {0, 6, 8, 4, 5, 9, 7, 3, 2, 1};
};
