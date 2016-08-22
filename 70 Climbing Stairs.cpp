class Solution {
public:
    int dfs(int x) {
        if  (f[x] !=  -1)
            return  f[x];
        int & t =  f[x];
        if  (x <=  1)
            return  t =  1;
        return  (t =  dfs(x -  1) +  dfs(x -  2));
    }
    int climbStairs(int n) {
        f.resize(n +  1);
        std::fill(f.begin(), f.end(), -1);
        return  dfs(n);
    }
private:
    vector< int>  f;    
};
