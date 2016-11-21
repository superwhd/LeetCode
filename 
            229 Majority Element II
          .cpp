class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<pair<int, int>> can(2, {0, 0});
        for (auto num : nums) {
            bool vis = false;
            if (!vis) {
                for (auto &t : can) {
                    if (t.first == num) {
                        vis = true;
                        t.second++;
                        break;
                    }
                }
            }
            if (!vis) {
                for (auto &t : can) {
                    if (!t.second) {
                        t.first = num;
                        t.second = 1;
                        vis = true;
                        break;
                    }
                }
            }
            if (!vis) {
                if (can[0].second) {
                    can[0].second--;
                }
                if (can[1].second) {
                    can[1].second--;
                }
            }
        }
        vector<int> ans;
        can[0].second = can[1].second = 0;
        for (auto num : nums) {
            for (auto &t : can) {
                if (t.first == num) {
                    t.second++;
                }
            }
        }
        for (auto &t : can) {
            if (t.second > nums.size() / 3) {
                ans.push_back(t.first);
            }
        }
        ans.erase(unique(begin(ans), end(ans)), end(ans));
        return ans;
    }
};
