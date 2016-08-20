class Solution {
public:
    bool isValidSudoku(vector< vector< char>>&  board) {
        if  (board.size() !=  9)
            return  false;
        int r[9][9], c[9][9], vis9[9][9];
        memset(r, 0, sizeof (r));
        memset(c, 0, sizeof (c));
        memset(vis9, 0, sizeof (vis9));
        for  (int i =  0; i <  9; i++ ) {
            if  (board[i].size() !=  9)
                return  false;
        }
        for  (int i =  0; i <  9; i++ ) {
            for  (int j =  0; j <  9; j++ ) {
                char ch =  board[i][j];
                if  ((ch <  '1' ||  ch >  '9') &&  ch !=  '.')
                    return  false;
                if  (ch !=  '.') {
                    r[i][ch -  '1']++ ;
                    c[j][ch -  '1']++ ;
                    vis9[i / 3 *  3 +  j / 3][ch -  '1']++ ;
                }
            }
        }
        for  (int i =  0; i <  9; i++ ) {
            for  (int j =  0; j <  9; j++ ) {
                if  (r[i][j] >  1 ||  c[i][j] >  1 ||  vis9[i][j] >  1)
                    return  false;
            }
        }
        return  true;
    }
};
