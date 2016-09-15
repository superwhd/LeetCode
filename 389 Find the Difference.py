class  Solution(object):
    def  findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        cnts =  collections.Counter(s)
        cntt =  collections.Counter(t)
        for  ch in  t:
            if  cnts[ch] !=  cntt[ch]:
                return  ch
