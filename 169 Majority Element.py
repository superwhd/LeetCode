class  Solution(object):
    def  majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt =  0
        now =  0
        for  num in  nums:
            if  not  cnt:
                now =  num
                cnt =  1
            elif  now ==  num:
                cnt +=  1
            else :
                cnt -=  1
        return  now
        
