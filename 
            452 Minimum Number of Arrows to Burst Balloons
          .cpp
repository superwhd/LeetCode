class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        using pii = pair<int, int>;
        sort(begin(points), end(points), [] (const pii &t1, const pii &t2) {return t1.second < t2.second;});
        long long now = -(1ll << 60);
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            if (points[i].first > now) {
                now = points[i].second;
                ans++;
            }
        }
        return ans;
    }
};
