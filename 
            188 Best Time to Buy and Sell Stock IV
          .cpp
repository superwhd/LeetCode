class Solution {
public:
    int maxProfit(int m, vector<int>& prices) {
        if (!m || prices.empty()) {
            return 0;
        }
        int n = prices.size();
        using pii = pair<int, int>;
        vector<pii> a;
        for (int i = 0; i < n; i++) {
            int j, k;
            for (j = i + 1; j < n && prices[j] <= prices[j - 1]; j++);
            j--;
            for (k = j + 1; k < n && prices[k] >= prices[k - 1]; k++);
            k--;
            a.emplace_back(j, k);
            // cout << j << ", " << k << endl;
            i = k;
        }
        vector<int> trs;
        stack<pii> st;
        for (int i = 0; i < a.size(); i++) {
            auto now = a[i];
            while (!st.empty() && prices[now.first] < prices[st.top().first]) {
                trs.push_back(prices[st.top().second] - prices[st.top().first]);
                st.pop();
            }
            while (!st.empty() && prices[now.first] >= prices[st.top().first] && prices[now.second] >= prices[st.top().second]
                ) {
                auto t = st.top();
                st.pop();
                trs.push_back(prices[t.second] - prices[now.first]);
                now = make_pair(t.first, now.second);
            }
            st.push(now);
        }
        while (!st.empty()) {
            trs.push_back(prices[st.top().second] - prices[st.top().first]);
            st.pop();
        }
        // for (auto tr : trs) {
        //     cout << tr << endl;
        // }
        m = min(m, int(trs.size()));
        nth_element(begin(trs), begin(trs) + m, end(trs), greater<int>());
        int ans = 0;
        for (int i = 0; i < m; i++) {
            ans += trs[i];
        }
        return ans;
    }
};
