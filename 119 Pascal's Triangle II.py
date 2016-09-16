class  Solution(object):
    def  getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        ans =  []
        now =  1
        for  i in  xrange(0, rowIndex +  1):
            ans.append(now)
            now *=  (rowIndex -  i)
            now /=  i +  1
        return  ans
