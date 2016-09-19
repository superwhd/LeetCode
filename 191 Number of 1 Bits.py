class  Solution(object):
    def  hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        res =  0
        while  n:
            n -=  n &  - n
            res +=  1
        return  res
