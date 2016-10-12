class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = num1.size(), m = num2.size();
        res.resize(max(n, m) + 1);
        for (int i = 0; i < n || i < m; i++) {
            if (i < n)
                res[i] += num1[i] - '0';
            if (i < m)
                res[i] += num2[i] - '0';
            if (res[i] >= 10) {
                res[i + 1]++;
                res[i] -= 10;
            }
            // printf("%d\n",res[i]);
        }
        if (!res[res.size() - 1])
            res.pop_back();
        for (int i = 0; i < res.size(); i++)
            res[i] += '0';
        reverse(res.begin(), res.end());
        return res;
    }
};
