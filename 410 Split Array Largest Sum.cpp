class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long s = 0, e = 1ll << 60;
        while (s <= e) {
            long long mid = s + e >> 1;
            if (check(nums, m, mid)) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
private:
    bool check(vector<int>&a, int m, long long x) {
        long long s = 0;
        int num = 1;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] > x)
                return false;
            if (s + a[i] > x) {
                s = a[i];
                num++;
            } else {
                s += a[i];
            }
        }
        return num <= m;
    }    
};
