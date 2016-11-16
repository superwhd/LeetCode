class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> q(k);
        vector<int> ans;
        int head = 0, tail = 0;
        auto next = [&] (int x) {
            return (x + 1) % k; 
        };
        auto prev = [&] (int x) {
            return (x - 1 + k) % k;
        };
        for (int i = 0; i < nums.size(); i++) {
            if (head != tail) {
                if (q[head] == i - k) {
                    head = next(head);
                }
            }
            while (head != tail && nums[q[prev(tail)]] <= nums[i]) {
                tail = prev(tail);
            }
            q[tail] = i;
            tail = next(tail);
            if (i >= k - 1) {
                ans.push_back(nums[q[head]]);
            }
        }
        return ans;
    }
};
