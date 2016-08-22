class  Solution(object):
    def  combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        f =  [0] *  (target +  1)
        f[0] =  1
        for  i in  xrange(0, target +  1):
            for  num in  nums:
                if  i >=  num:
                    f[i] +=  f[i -  num]
        return  f[target]
