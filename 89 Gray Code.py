class  Solution(object):
    def  grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def  go(n):
            if  n ==  0:
                return  [0]
            a =  go(n -  1)
            return  a +  [((1 <<  (n -  1)) |  num) for  num in  a][::- 1]
        return  go(n)
