class  Solution(object):
    def  sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        cnt =  collections.Counter(nums)
        for  i in  xrange(len(nums)):
            if  i <  cnt[0]:
                nums[i] =  0
            elif  i <  cnt[0] +  cnt[1]:
                nums[i] =  1
            else :
                nums[i] =  2
        
