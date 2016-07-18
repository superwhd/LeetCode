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
    static bool cmp(const Interval &t1, const Interval &t2) {
        return t1.start < t2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        Interval tmp;
        for (int i = 0; i < intervals.size(); i++) {
            Interval &interval = intervals[i];
            if (!i) {
                tmp = interval;
            } else {
                if (interval.start > tmp.end) {
                    res.push_back(tmp);
                    tmp = interval;
                } else {
                    tmp.end = max(tmp.end, interval.end);
                }
            }
        }
        if (intervals.size())
            res.push_back(tmp);
        return res;
    }
};