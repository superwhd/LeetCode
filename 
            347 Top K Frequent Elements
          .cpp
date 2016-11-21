class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto num : nums) {
            cnt[num]++;
        }
        vector<pair<int, int>> pairs; 
        for (auto &it : cnt) {
            pairs.emplace_back(it.second, it.first);
        }
        sort(begin(pairs), end(pairs), greater<pair<int, int>>());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.emplace_back(pairs[i].second);
        }
        return ans;
    }
};
