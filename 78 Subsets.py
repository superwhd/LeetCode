class  Solution(object):
    def  subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n =  len(nums)
        ans =  []
        for  i in  xrange(0, 1 <<  n):
            tmp =  []
            for  j in  xrange(0, n):
                if  i >>  j &  1:
                    tmp.append(nums[j])
            ans.append(tmp)
        return  ans
