class Solution {
public:
    bool isMatch(string s, string p) {
        vector< vector< bool>  >  f(s.size() +  1, vector< bool> (p.size() +  1));
        f[0][0] =  true;
        for  (int i =  0; i <=  s.size(); i++ )
            for  (int j =  0; j <=  p.size(); j++ ) {
                if  (! i &&  ! j)
                    continue ;
                if  (i &&  j &&  (s[i -  1] ==  p[j -  1] ||  p[j -  1] ==  '?') &&  f[i -  1][j -  1])
                    f[i][j] =  true;
                if  (j &&  p[j -  1] ==  '*' &&  f[i][j -  1])
                    f[i][j] =  true;
                if  (i &&  j &&  p[j -  1] ==  '*' &&  f[i -  1][j])
                    f[i][j] =  true;
            }
        return  f[s.size()][p.size()];
    }
};
