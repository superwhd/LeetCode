class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        if (1 >= str.size()) {
            return false;
        }
        vector<int> facs;
        for (int i = 1; i * i <= str.size(); i++) {
            if (str.size() % i == 0) {
                facs.push_back(i);
                if (i > 1 && i * i != str.size()) {
                    facs.push_back(str.size() / i);
                }
            }
        }
        for (auto d : facs) {
            int i;
            for (i = 0; i < str.size(); i++) {
                if (str[i] != str[i % d]) {
                    break;
                }
            }
            if (i == str.size()) {
                return true;
            }
        }
        return false;
    }
};
