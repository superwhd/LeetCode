class  Solution(object):
    def  plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        if  not  digits:
            return  [1]
        digits[- 1] +=  1
        res =  [0] +  digits
        for  i in  xrange(len(res) -  1, - 1, - 1):
            if  res[i] >=  10:
                res[i] -=  10
                res[i -  1] +=  1
        if  res[0]:
            return  res
        return  res[1:]
        
