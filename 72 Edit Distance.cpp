class Solution {
public:
    int minDistance(string word1, string word2) {
        int n =  word1.size(), m =  word2.size();
        vector< vector< int>>  f(n +  1, vector< int> (m +  1));
        for  (int i =  0; i <=  n; i++ )
            for  (int j =  0; j <=  m; j++ )
                if  (i ||  j) {
                    f[i][j] =  n +  m +  1;
                    if  (i)
                        f[i][j] =  min(f[i][j], f[i -  1][j] +  1);
                    if  (j)
                        f[i][j] =  min(f[i][j], f[i][j -  1] +  1);
                    if  (i &&  j) {
                        f[i][j] =  min(f[i][j], f[i -  1][j -  1] +  (word1[i -  1] !=  word2[j -  1]));
                    }
                }
        return  f[n][m];
    }
};
