class Solution {
public:
    int find(vector< int>  & nums, int s, int e, int target) {
        if  (s >  e) {
            return  -1;
        }
        int mid;
        while  (s <=  e) {
            mid =  s +  e >>  1;
            if  (nums[mid] ==  target)
                return  mid;
            if  (nums[mid] <  target)
                s =  mid +  1;
            else  
                e =  mid -  1;
        }
        return  -1;
    }
    int search(vector< int>&  nums, int target) {
        if  (! nums.size())
            return  -1;
        int pos =  0;
        for  (int i =  30; i >=  0; i-- ) {
            if  (0ll +  pos +  (1 <<  i) <  nums.size() &&  nums[0] <  nums[pos +  (1 <<  i)]) {
                pos +=  (1 <<  i);
            }
        }
        pos++ ;
        pos %=  nums.size();
        if  (target <=  nums[nums.size() -  1]) {
            return  find(nums, pos, nums.size() -  1, target);
        } else  {
            return  find(nums, 0, pos -  1, target);
        }
    }
};
