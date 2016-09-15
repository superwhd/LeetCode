class  Solution(object):
    def  validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        data =  [num &  ((1 <<  8) -  1) for  num in  data]
        i =  0
        while  i <  len(data):
            def  count1s(num):
                s =  0
                for  i in  xrange(7, - 1, - 1):
                    if  num >>  i &  1:
                        s +=  1
                    else :
                        break 
                return  s
            num =  data[i]
            cnt =  count1s(num)
            if  cnt >  4 or  cnt ==  1:
                return  False
            if  cnt:
                cnt -=  1
            while  cnt and  i +  1 <  len(data):
                i +=  1
                cnt -=  1
                if  count1s(data[i]) !=  1:
                    return  False
            if  cnt:
                return  False
            i +=  1
        return  True
                
        
