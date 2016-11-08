class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {        
        int n = A.size();
        vector<unordered_map<long long, int>> f(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = 0ll + A[i] - A[j];
                if (f[j].count(d)) {
                    f[i][d] += f[j][d];
                    ans += f[j][d];
                } 
                f[i][d] += 1;
                ans++;
            }
        }
        ans -= n * (n - 1) / 2;
        return ans;
    }
};
