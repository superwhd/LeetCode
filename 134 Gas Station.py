class  Solution(object):
    def  canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        a =  [t[0] -  t[1] for  t in  zip(gas, cost)] *  2
        cnt =  0
        res =  0
        sum =  0
        i =  0
        for  t in  a:
            sum +=  t
            if  sum <  0:
                cnt =  0
                sum =  0
                res =  (i +  1) %  len(gas)
            else :
                cnt +=  1
            i +=  1
            if  cnt >=  len(gas):
                return  res
        return  - 1
                
