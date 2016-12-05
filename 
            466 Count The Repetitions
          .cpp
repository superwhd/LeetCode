class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int, pair<int, int>> to;
        unordered_map<int, int> lastvis;
        int now = 0;
        lastvis[now] = 0;
        int len = 0;
        while (true) {
            int add = 0, last = now;
            for (int j = 0; j < s2.size(); j++) {
                int cnt = 0;
                while (s1[now] != s2[j]) {
                    now = (now + 1) % s1.size();
                    cnt++;
                    if (cnt > s1.size()) {
                        return 0;
                    }
                    if (!now) {
                        add++;
                    }
                }
                now = (now + 1) % s1.size(); 
                if (!now) {
                    add++;
                }
            }
            // cout << now << endl;
            to[last] = make_pair(add, now);
            if (!lastvis.count(now)) {
                lastvis[now] = lastvis[last] + add;
            } else {
                len = lastvis[last] + add - lastvis[now];
                break;
            }
        }
        int sum = 0, x = 1, y = 0;
        while (y != now && x < n1) {
            // cout << x << " " << y << endl;
            auto t = to[y];
            x += t.first;
            y = t.second;
            sum++;
        }
        int bincrease = 0;
        {
            int xx = x, yy = y;
            while (true) {
                auto t = to[yy];
                xx += t.first;
                yy = t.second;
                bincrease++;
                if (yy == y) {
                    break;
                }
            }
        }
        cout << len << endl;
        sum += (n1 - x) / len * bincrease;
        x += (n1 - x) / len * len;
        cout << sum << " " << bincrease << endl;
        cout << x << " " << y << endl;
        while (x + to[y].first <= n1) {
            auto t = to[y];
            x += t.first;
            y = t.second;
            sum++;
        }
        cout << to[y].first << " " << to[y].second << endl;
        while (true) {
            auto t = to[y];
            x += t.first;
            y = t.second;
            cout << x << " " << y << endl;
            if ((x == n1 + 1 && y) || x > n1 + 1) {
                break;
            }
            sum++;
        }
        return sum / n2;
    }
};
