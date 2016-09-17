class Solution {
public:
    void setZeroes(vector< vector< int>>&  matrix) {
        if  (! matrix.size())
            return ;
        int n =  matrix.size(), m =  matrix[0].size();
        bool firstRow0 =  false;
        for  (int j =  0; j <  m; j++ )
            firstRow0 |=  ! matrix[0][j];
        for  (int i =  1; i <  n; i++ ) {
            for  (int j =  0; j <  m; j++ ) {
                if  (! matrix[i][j])
                    matrix[i][0] =  matrix[0][j] =  0;
            }
        }
        for  (int i =  n -  1; i >  0; i-- ) {
            for  (int j =  m -  1; j >=  0; j-- ) {
                if  (! matrix[i][0] ||  ! matrix[0][j]) {
                    matrix[i][j] =  0;
                }
            }
        }
        if  (firstRow0)
            for  (int j =  0; j <  m; j++ )
                matrix[0][j] =  0;
    }
};
