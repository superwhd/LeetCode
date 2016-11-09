class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans{1};
        vector<int> index(primes.size());
        for (int i = 0; i + 1 < n; i++) {
            long long x = primes[0] * ans[index[0]];
            for (int j = 0; j < primes.size(); j++) {
                x = min(x, 1ll * primes[j] * ans[index[j]]);
            }
            ans.push_back(x);
            for (int j = 0; j < primes.size(); j++) {
                index[j] += (1ll * primes[j] * ans[index[j]] == x);
            }
        }
        return ans[n - 1];
    }
};
