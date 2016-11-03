class Solution {
public:
    int thirdMax(vector<int>& nums) {
        const int inf = 0x7fffffff;
        vector<int> ans{-inf - 1, -inf - 1, -inf - 1};
        bool vis[3] = {false, false, false};
        for (auto x : nums) {
            for (int i = 0; i < 3; i++) {
                if (vis[i]) {
                    if (x == ans[i]) {
                        break;
                    }
                    if (x > ans[i]) {
                        int j;
                        for (j = 2; j > i; j--) {
                            if (vis[j]) {
                                break;
                            }
                        }
                        j++;
                        vis[j] = true;
                        for (; j > i; j--) {
                            ans[j] = ans[j - 1];
                        } 
                        ans[i] = x;
                        break;
                    }
                } else {
                    ans[i] = x;
                    vis[i] = true;
                    break;
                }
            }
        }
        if (!vis[2]) {
            return ans[0];
        } else {
            return ans[2];
        }
    }
};
