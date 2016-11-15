class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        root = init(0, nums.size() - 1);
        vector<pair<int, int>> a;
        for (int i = 0; i < nums.size(); i++) {
            a.push_back(make_pair(nums[i], i));
        }
        sort(begin(a), end(a));
        for (auto &tmp : a) {
            int pos = tmp.second, val = tmp.first;
            insert(root, pos, val);
            int lf = get(root, 0, pos - 1).first;
            int rt = get(root, pos + 1, nums.size() - 1).second;
            // cout << lf << " " << rt << endl;
            if (rt > lf) {
                return true;
            }
        }
        return false;
    }
    const int inf = 0x7fffffff;
    struct node {
        node *c[2];
        int l, r, mn, mx;
    } *root;
    node *init(int l, int r) {
        if (l > r) {
            return nullptr;
        }
        node *p = new node();
        p->l = l;
        p->r = r;
        p->mn = inf;
        p->mx = -inf - 1;
        if (l == r) {
            return p;
        }
        int mid = l + r >> 1;
        p->c[0] = init(l, mid);
        p->c[1] = init(mid + 1, r);
        return p;
    }
    void insert(node *x, int pos, int val) {
        if (x->l == x->r) {
            x->mn = x->mx = val;
            return ;
        }
        int mid = x->l + x->r >> 1;
        insert(x->c[pos > mid], pos, val);
        x->mn = min(x->c[0]->mn, x->c[1]->mn);       
        x->mx = max(x->c[0]->mx, x->c[1]->mx);
    }
    pair<int, int> get(node *x, int l, int r) {
        if (l > r) {
            return make_pair(inf, -inf - 1);
        }
        if (l <= x->l && x->r <= r) {
            return make_pair(x->mn, x->mx);
        }
        int mid = x->l + x->r >> 1;
        pair<int, int> res(inf, -inf - 1);
        if (l <= mid) {
            auto tmp = get(x->c[0], l, r);
            res.first = min(res.first, tmp.first);
            res.second = max(res.second, tmp.second);
        }
        if (r > mid) {
            auto tmp = get(x->c[1], l, r);
            res.first = min(res.first, tmp.first);
            res.second = max(res.second, tmp.second);
        }
        return res;
    }
};
