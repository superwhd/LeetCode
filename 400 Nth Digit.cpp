class Solution {
public:
    int findNthDigit(int n) {
        int pw =  1, t;
        for  (t =  1; ; t++ ) {
            if  (n <=  1ll *  t *  pw *  9) {
                break ;
            }
            n -=  t *  pw *  9;
            pw *=  10;
        }
        int quotien =  (n -  1) / t, rem =  (n -  1) %  t;
        int target =  quotien +  pw;
        // cout << target << "," << rem << ",";
        vector< int>  vec;
        while  (target) {
            vec.push_back(target %  10);
            target /=  10;
        }
        reverse(vec.begin(), vec.end());
        return  vec[rem];
    }
};
