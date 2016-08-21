class Solution {
public:
    void nextPermutation(vector< int>&  nums) {
        if  (nums.size() <=  1)
            return  ;
        int i, j, k;
        for  (i =  nums.size() -  2; i >=  0; i-- ) 
            if  (nums[i] <  nums[i +  1])
                break ;
        if  (i <  0) {
            sort(nums.begin(), nums.end());
            return  ;
        }
        int minIndex =  i +  1;
        for  (j =  i +  1; j <  nums.size(); j++ ) {
            if  (nums[j] >  nums[i] &&  nums[j] <  nums[minIndex])
                minIndex =  j;
        }
        swap(nums[i], nums[minIndex]);
        sort(nums.begin() +  i +  1, nums.end());
    }
};
