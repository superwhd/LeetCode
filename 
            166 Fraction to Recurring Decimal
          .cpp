class Solution {
public:
    string fractionToDecimal(int numeratorInt, int denominatorInt) {
        string res;
        auto myabs = [] (long long x) {
            return x > 0 ? x : -x;
        };
        long long numerator = numeratorInt, denominator = denominatorInt;
        if (numerator * denominator < 0) {
            res += "-";
            numerator = myabs(numerator);
            denominator = myabs(denominator);
        }
        res += to_string(numerator / denominator);
        if (numerator % denominator) {
            res.push_back('.');
            map<long long, int> remainders;
            vector<long long> quotients;
            long long remainder = numerator % denominator;
            while (remainder && !remainders.count(remainder)) {                
                auto quotient = remainder * 10 / denominator;
                remainders[remainder] = quotients.size();
                quotients.push_back(quotient);
                remainder = remainder * 10 % denominator;
            }
            if (!remainder) {
                for (auto quotient : quotients) {
                    res += to_string(quotient);
                }
            } else {
                int start = remainders[remainder];
                for (int i = 0; i < start; i++) {
                    res += to_string(quotients[i]);
                }
                res += "(";
                for (int i = start; i < quotients.size(); i++) {
                    res += to_string(quotients[i]);
                }
                res += ")";
            }
        }
        return res;
    }
};
