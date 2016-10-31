class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        struct Node {
            shared_ptr<Node> c[2];
        };
        using ptr = shared_ptr<Node>; 
        ptr root(new Node());
        auto insert = [&] (int num) {
            ptr now = root;
            for (int k = 30; k >= 0; k--) {
                auto c = num >> k & 1;
                if (!now->c[c]) {
                    now->c[c] = ptr(new Node());
                }
                now = now->c[c];
            }  
        };
        auto find = [&] (int num) {
            ptr now = root;
            int ans = 0;
            for (int k = 30; k >= 0; k--) {
                auto c = !(num >> k & 1);
                if (now->c[c]) {
                    ans += 1 << k;
                } else {
                    c = !c;
                }
                now = now->c[c];
            }
            return ans;
        };
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i) {
                ans = max(ans, find(nums[i]));
            }
            insert(nums[i]);
        }
        return ans;
    }
};
