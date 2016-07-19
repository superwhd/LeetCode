class Solution {
public:
    void dfs(int dep, vector<int> now) {
        if (dep == n) {
            ans.push_back(now);
            return;
        }
        for (int i = 0; i < a.size(); i++)
            if (a[i].second > 0) {
                vector<int> new_vec = now;
                new_vec.push_back(a[i].first);
                a[i].second--;
                dfs(dep + 1, new_vec);
                a[i].second++;
            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j;
            for (j = i; j < nums.size() && nums[i] == nums[j]; j++);
            a.push_back(make_pair(nums[i], j - i));
            i = j - 1;
        }
        dfs(0, vector<int>());
        return ans;
    }
private:
    vector<pair<int, int>> a;
    vector<vector<int>> ans;
    int n;
};