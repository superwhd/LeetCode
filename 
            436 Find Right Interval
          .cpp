/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> slx;
        for (auto interval : intervals) {
            slx.push_back(interval.start);
            slx.push_back(interval.end);
        }
        sort(slx.begin(), slx.end());
        slx.erase(unique(begin(slx), end(slx)), end(slx));
        auto g = [&] (int x) {
            return slx.size() - (lower_bound(begin(slx), end(slx), x) - begin(slx) + 1) + 1;
        };
        auto getmin = [&] (int x, int y) {
            if (x == -1) {
                return y;
            }
            if (intervals[x].start <= intervals[y].start) {
                return x;
            }
            return y;
        };
        vector<int> tr(slx.size() + 1, -1);
        auto add = [&] (int x, int y) {
            for (; x <= slx.size(); x += x & -x) {
                tr[x] = getmin(tr[x], y);
            }
        };
        auto get = [&] (int x) {
            int ans = -1;
            for (; x; x -= x & -x) {
                ans = getmin(ans, tr[x]);
            }
            return ans;
        };
        vector<int> ans;
        for (int i = intervals.size() - 1; i >= 0; i--) {
            add(g(intervals[i].start), i);
        }
        for (int i = intervals.size() - 1; i >= 0; i--) {
            auto &interval = intervals[i];
            int x = get(g(interval.end));
            if (x == -1) {
                ans.push_back(-1);
            } else {
                ans.push_back(x);
            }
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
