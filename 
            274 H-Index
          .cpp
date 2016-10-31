class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(begin(citations), end(citations));
        int l = 0, r = citations.size();
        auto ck = [&] (int x) {
            return end(citations) - lower_bound(begin(citations), end(citations), x) >= x;
        };
        while (l <= r) {
            int mid = l + r >> 1;
            if (ck(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};
