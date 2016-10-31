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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(begin(intervals), end(intervals), [] (const Interval &a, const Interval &b) {return a.end < b.end;});
        int last = -0x7fffffff - 1;
        int ans = 0;
        for (auto &interval : intervals) {
            if (interval.start >= last) {
                last = interval.end;
                ans++;
            }
        }
        return intervals.size() - ans;
    }
};
