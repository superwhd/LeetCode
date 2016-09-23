class Solution {
public:
    int maxCoins(vector< int>&  nums) {
        a =  nums;
        memset(f, -1, sizeof (f));
        return  dfs(0, a.size() -  1);
    }
private:
    vector< int>  a;
    int f[503][503];
    int dfs(int l, int r) {
        if  (l >  r)
            return  0;
        if  (f[l][r] !=  -1)
            return  f[l][r];
        int & x =  f[l][r];
        x =  0;  
        int w1 =  (l ==  0) ? 1 : a[l -  1];
        int w2 =  (r +  1 ==  a.size()) ? 1 : a[r +  1];
        for  (int k =  l; k <=  r; k++ ) {
            x =  max(x, dfs(l, k -  1) +  dfs(k +  1, r) +  w1 *  a[k] *  w2);
        }
        // cout << l << " " << r << " " << x << endl;
        return  x;
    }
};
