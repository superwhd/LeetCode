class Solution {
public:
    typedef long long big;

    int divide(int dividend, int divisor) {
        int MAX_INT =  2147483647;
        if  (! divisor)
            return  MAX_INT;
        if  (dividend ==  -2147483648 &&  divisor ==  -1)
            return  MAX_INT;
        big res =  0;
        int i;
        int flag =  1;
        if  (dividend <  0)
            flag =  - flag;
        if  (divisor <  0)
            flag =  - flag;
        big b_dividend =  dividend, b_divisor =  divisor;
        b_dividend =  b_dividend <  0 ? - b_dividend : b_dividend;
        b_divisor =  b_divisor <  0 ? - b_divisor : b_divisor;
        for  (i =  31; i >=  0; i-- )
            if  (b_dividend >=  ((1ll *  b_divisor) <<  i)) {
                res +=  1 <<  i;
                b_dividend -=  ((1ll *  b_divisor) <<  i);
            }
        if  (flag <  0)
            res =  - res;
        return  res;
    }
};
