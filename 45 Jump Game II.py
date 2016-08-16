class  Solution(object):
    def  jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        f =  [0] *  len(nums)
        g =  [0] *  (len(nums) +  1)
        j =  0
        for  i, num in  enumerate(nums):
            while  g[j] <  i:
                j +=  1
            f[i] =  j
            g[j +  1] =  max(g[j +  1], i +  num)
        return  f[len(nums) -  1]
        
