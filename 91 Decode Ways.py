class  Solution(object):
    def  numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if  not  s:
            return  0
        f =  [0] *  (len(s) +  1)
        f[0] =  1
        for  i in  xrange(1, len(s) +  1):
            if  s[i -  1] !=  '0':
                f[i] +=  f[i -  1]
            if  i >  1 and  1 <=  int(s[i -  2 : i]) <=  26 and  s[i -  2] !=  '0':
                f[i] +=  f[i -  2]
        return  f[len(s)]
