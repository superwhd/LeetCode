class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        using namespace std;
        sort(nums.begin(), nums.end());
        unordered_map<int, shared_ptr<set<pair<int, int> > > >f;
        set<vector<int> > ans_set;
        for (int i3 = 0; i3 < nums.size(); i3++) {
            for (int i4 = i3 + 1; i4 < nums.size(); i4++) {
                if (i4 > i3 + 1 && nums[i4] == nums[i4 - 1])
                    continue;
                int sum34 = nums[i3] + nums[i4];
                if (sum34 * 2 < target)
                    continue;
                if (f.count(target - sum34)) {
                    for (auto &pair12 : *f[target - sum34]) {
                        vector<int> tmp {pair12.first, pair12.second, nums[i3], nums[i4]};
                        ans_set.insert(tmp);
                    }
                }
            }
            int i2 = i3;
            for (int i1 = 0; i1 < i2; i1++) {
                if (i1 && nums[i1] == nums[i1 - 1])
                    continue;
                int x = min(nums[i1], nums[i2]), y = max(nums[i1], nums[i2]);
                int sum12 = x + y;
                if (sum12 * 2 > target)
                    continue;
                if (!f.count(sum12)) {
                    f[sum12] = shared_ptr<set<pair<int, int> > >(new set<pair<int, int> >());
                }
                f[sum12]->insert(make_pair(x, y));
            }
        }
        vector<vector<int> > ans;
        for (auto &t : ans_set) {
            ans.push_back(t);
        }
        return ans;
    }
};