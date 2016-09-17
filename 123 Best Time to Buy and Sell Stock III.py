class  Solution(object):
    def  maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n =  len(prices) +  1
        f =  [[- 99999999] *  5 for  i in  xrange(n)]
        f[0][0] =  0
        for  i in  xrange(1, n):
            for  j in  xrange(0, 5):
                price =  prices[i -  1]
                f[i][j] =  f[i -  1][j]
                if  j &  1:
                    f[i][j] =  max(f[i][j], f[i -  1][j -  1] -  price)
                else :
                    if  j >  1:
                        f[i][j] =  max(f[i][j], f[i -  1][j -  1] +  price)
        return  max(f[n -  1])
