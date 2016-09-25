class  Solution(object):
    def  toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        def  c(x):
            if  x <=  9:
                return  chr(ord('0') +  x)
            return  chr(ord('a') +  x -  10)
        if  num <  0:
            num +=  1 <<  32
        ans =  ''
        for  i in  xrange(7, - 1, - 1):
            ans +=  c(num >>  (i *  4) &  15)
        i =  0
        while  i <  len(ans) and  ans[i] ==  '0':
            i +=  1
        ans =  ans[i:]
        if  not  ans:
            ans =  '0'
        return  ans
