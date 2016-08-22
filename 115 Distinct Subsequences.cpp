class Solution {
public:
    int numDistinct(string s, string t) {
        int f[s.size() +  1][t.size() +  1];
        memset(f, 0, sizeof (f));
        f[0][0] =  1;
        for  (int i =  0; i <=  s.size(); i++ ) {
            for  (int j =  0; j <=  t.size(); j++ ) {
                if  (! i &&  ! j)
                    continue ;
                if  (i)
                    f[i][j] +=  f[i -  1][j];
                if  (i &&  j &&  s[i -  1] ==  t[j -  1])
                    f[i][j] +=  f[i -  1][j -  1];
            }
        }
        return  f[s.size()][t.size()];
    }
};
