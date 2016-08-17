class Solution {
public:
    int searchInsert(vector< int>&  nums, int target) {
        if  (! nums.size())
            return  0;
        int b =  0, e =  nums.size() -  1, mid;
        while  (b <=  e) {
            mid =  (b +  e) >>  1;
            if  (target ==  nums[mid])
                return  mid;
            if  (target <  nums[mid])
                e =  mid -  1;
            else  b =  mid +  1;
        }
        return  b;
    }
};
