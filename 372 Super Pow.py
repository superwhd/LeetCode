class  Solution(object):
    def  superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        b =  int(''.join([chr(ch +  ord('0')) for  ch in  b]))
        ans =  1
        a %=  1337
        while  b:
            if  b &  1:
                ans =  ans *  a %  1337
            b >>=  1
            a =  a *  a %  1337
        return  ans
