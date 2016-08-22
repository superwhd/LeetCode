class  Solution(object):
    def  singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        xorRes =  reduce(lambda  x, y : x ^  y, nums)
        lastBit =  xorRes &  -  xorRes
        ansA, ansB =  0, 0
        for  num in  nums:
            if  num &  lastBit:
                ansA ^=  num
            else :
                ansB ^=  num
        return  ansA, ansB
        
