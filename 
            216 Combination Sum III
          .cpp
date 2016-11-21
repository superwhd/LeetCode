class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        function<void(vector<int>, int)> dfs = [&] (vector<int> nums, int sum) {
            if (nums.size() == k) {
                if (sum == n) {
                    ans.emplace_back(nums);
                }  
                return ;
            }
            for (int i = (nums.size() ? nums.back() + 1 : 1); i <= 9 && i + sum <= n; i++) {
                int restNum = k - nums.size() - 1;
                int restSum = (i + 1 + restNum + i) * restNum / 2;
                if (n - sum - i >= restSum && n - sum - i <= 9 * restNum) {
                    nums.push_back(i);
                    dfs(nums, sum + i);
                    nums.pop_back();
                }
            }
        };
        dfs({}, 0);
        return ans;
    }
};
