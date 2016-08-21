class  Solution(object):
    def  canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        def  counter(string):
            cnt =  [sum([1 for  ch in  string if  ord(ch) ==  alpha]) for  alpha in  range(ord('a'), ord('z') +  1)]
            return  cnt
        
        cnt1 =  counter(ransomNote)
        cnt2 =  counter(magazine)
        for  ch in  range(ord('a'), ord('z') +  1):
            if  cnt1[ch -  ord('a')] >  cnt2[ch -  ord('a')]:
                return  False
        return  True
