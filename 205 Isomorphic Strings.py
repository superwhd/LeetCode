class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        def convert(s, t):
            dic = dict([(s[i], t[i]) for i in xrange(len(s))])
            tt = ''.join([dic[c] for c in s])
            return tt == t
            
        return convert(s, t) and convert(t, s)
