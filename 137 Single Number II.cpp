class Solution {
public:
    int singleNumber(vector< int>&  nums) {
        vector< int>  cnt(32);
        for  (auto num : nums) {
            for  (int i =  0; i <  32; i++ ) {
                if  (num >>  i &  1)
                    cnt[i]++ ;
            }
        }
        int ans =  0;
        for  (int i =  0; i <  32; i++ ) {
            if  (cnt[i] %  3)
                ans +=  1 <<  i;
        }
        return  ans;
    }
};
