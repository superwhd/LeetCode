class  Solution(object):
    def  integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        if  n ==  2:
            return  1
        if  n ==  3:
            return  2
        if  n ==  5:
            return  6
        cnt3 =  n /  3
        if  n %  3 ==  0:
            return  3 **  cnt3
        if  n %  3 ==  2:
            return  3 **  cnt3 *  2
        return  3 **  (cnt3 -  1) *  4
