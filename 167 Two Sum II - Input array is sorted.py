class  Solution(object):
    def  twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        a =  [(num, index) for  index, num in  enumerate(numbers)]
        l =  0
        r =  len(a) -  1
        while  l <  r:
            while  r >  l +  1 and  a[l][0] +  a[r][0] >  target:
                r -=  1
            if  a[l][0] +  a[r][0] ==  target:
                return  [a[l][1] +  1, a[r][1] +  1]
            l +=  1
