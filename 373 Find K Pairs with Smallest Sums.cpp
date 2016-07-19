class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using pii = pair<int, int>;
        using it = vector<int>::iterator;
        k = min(int(nums1.size() * nums2.size()), k);
        if (!k)
            return vector<pair<int, int>>();
        priority_queue<pair<int, pair<it, it>>> heap;
        int t = 0;
        for (int &x : nums1) 
            heap.push(make_pair(-x - nums2[0], make_pair(it(&x), nums2.begin())));
        vector<pii> ans;
        while (ans.size() < k) {
            auto tmp = heap.top();
            heap.pop();
            ans.push_back(make_pair(*(tmp.second.first), *(tmp.second.second)));
            tmp.second.second++;
            if (tmp.second.second != nums2.end()) {
                tmp.first = -*(tmp.second.first) - *(tmp.second.second);
                heap.push(tmp);
            }
        }
        return ans;
    }
};