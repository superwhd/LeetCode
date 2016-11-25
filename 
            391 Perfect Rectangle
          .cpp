class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        using pii = pair<int, int>;
        using big = long long;
        map<pii, int> cnt;
        big sumArea = 0ll;
        auto area = [] (const vector<int> &rec) {
            return 1ll * (0ll + rec[3] - rec[1]) * (0ll + rec[2] - rec[0]);
        };
        vector<int> boundary = rectangles[0];
        auto update = [] (vector<int> &c1, const vector<int> &c2) {
            for (int i = 0; i < 2; i++) {
                c1[i] = min(c1[i], c2[i]);
            }
            for (int i = 2; i < 4; i++) {
                c1[i] = max(c1[i], c2[i]);
            }
        };
        for (auto &rect : rectangles) {
            sumArea += area(rect);
            update(boundary, rect);
            for (auto x : {rect[0], rect[2]}) {
                for (auto y : {rect[1], rect[3]}) {
                    cnt[make_pair(x, y)]++;
                }
            }
        }
        if (sumArea != area(boundary)) {
            return false;
        }
        for (auto &p : cnt) {
            if (p.second == 1) {
                auto pos = p.first;
                if ((pos.first != boundary[0] && pos.first != boundary[2]) || (pos.second != boundary[1] && pos.second != 
                    boundary[3])) {
                    return false;
                }
            } else if (p.second == 3) {
                return false;
            }
        }
        for (auto x : {boundary[0], boundary[2]}) {
            for (auto y : {boundary[1], boundary[3]}) {
                if (!cnt.count(make_pair(x, y)) || cnt[make_pair(x, y)] != 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
