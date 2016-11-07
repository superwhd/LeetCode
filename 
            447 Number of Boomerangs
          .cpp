class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        auto getdis = [] (const pair<int, int> &t1, const pair<int, int> &t2) {
            return (t1.first - t2.first) * (t1.first - t2.first) + (t1.second - t2.second) * (t1.second - t2.second);
        };
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            vector<int> dis;
            for (int j = 0; j < points.size(); j++) {
                if (j != i) {
                    dis.push_back(getdis(points[i], points[j]));
                }
            }
            sort(begin(dis), end(dis));
            int k, j;
            for (j = 0; j < dis.size(); j++) {
                for (k = j; k < dis.size() && dis[k] == dis[j]; k++);
                ans += (k - j) * (k - j - 1);
                j = k - 1;
            }
        }
        return ans;
    }
};
