class  Solution(object):
    def  canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        maxReach =  0
        for  i, num in  enumerate(nums):
            if  maxReach <  i:
                return  False
            maxReach =  max(maxReach, i +  num)
        return  True
            
