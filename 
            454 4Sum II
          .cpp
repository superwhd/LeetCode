class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> f;
        int ans = 0;
        for (auto a : A) {
            for (auto b : B) {
                f[a + b]++;
            }
        }
        for (auto c : C) {
            for (auto d : D) {
                auto it = f.find(-c - d);
                if (it != end(f)) {
                    ans += it->second;
                }
            }
        }
        return ans;
    }
};
