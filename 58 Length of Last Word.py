class  Solution(object):
    def  lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        arr =  [tmp for  tmp in  s.split(' ') if  tmp]
        if  len(arr) <  1:
            return  0
        return  len(arr[- 1])
        
