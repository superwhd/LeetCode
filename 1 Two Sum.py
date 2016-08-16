class  Solution(object):
    def  twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        a =  sorted([(num, index) for  index, num in  enumerate(nums)])
        l =  0
        r =  len(nums) -  1
        while  l <  r:
            while  r >  l +  1 and  a[l][0] +  a[r][0] >  target:
                r -=  1
            if  a[l][0] +  a[r][0] ==  target:
                return  [a[l][1], a[r][1]]
            l +=  1
