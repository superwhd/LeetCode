class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> isNotPrime(n, false);
        for (int i = 2; i < n; i++) {
            if (!isNotPrime[i]) {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; j++) {
                isNotPrime[i * primes[j]] = true;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        return primes.size();
    }
};
