/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto inInterval = [&] (Interval &interval, int x) {
            return interval.start <= x && x <= interval.end;
        };
        for (int i = 0; i < intervals.size(); i++) {
            if (inInterval(intervals[i], val)) {
                return ;
            }
        }
        bool merged = false;
        int id1 = -1, id2 = -1;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start == val + 1) {
                merged = true;
                id1 = i;
                intervals[i].start = val;
            }
            if (intervals[i].end == val - 1) {
                merged = true;
                id2 = i;
                intervals[i].end = val;
            }
        }
        if (id1 != -1 && id2 != -1) {            
            intervals[id1].start = intervals[id2].start;
            swap(intervals[id2], intervals[intervals.size() - 1]);
            intervals.pop_back();
        }
        if (!merged) {
            intervals.emplace_back(val, val);
        }
        sort(begin(intervals), end(intervals), [] (Interval &i1, Interval &i2) {return i1.start < i2.start;});
    }
    
    vector<Interval> getIntervals() {
        return intervals;
    }
private:
    vector<Interval> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
