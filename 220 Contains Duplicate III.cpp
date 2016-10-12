class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> f;
        k = max(k, 0);
        if (t < 0)
            return false;
        for (int i = 0; i < nums.size(); i++) {
            if (i)
                f.insert(nums[i - 1]);
            if (i >= k + 1)
                f.erase(nums[i - k - 1]);
            if (i) {
                auto itl = f.lower_bound(0ll + nums[i] - t);
                if (itl == f.end()) 
                    continue;
                auto itr = f.upper_bound(0ll + nums[i] + t);
                if (itr == f.begin()) 
                    continue;
                --itr;
                if (*itl <= *itr)
                    return true;
            }
        }
        return false;
    }
};
