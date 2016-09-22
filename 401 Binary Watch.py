class  Solution(object):
    def  readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        def  cnt(x):
            s =  0
            while  x:
                x -=  x &  - x
                s +=  1
            return  s
            
        ans =  []
        for  i in  xrange(0, 1024):
            if  cnt(i) ==  num:
                x =  i /  64
                y =  i %  64
                if  x <=  11 and  y <=  59:
                    ans.append(str(x) +  ":" +  str(y).zfill(2))
        return  ans
