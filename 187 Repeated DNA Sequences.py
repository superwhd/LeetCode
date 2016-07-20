class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        if len(s) < 10:
            return []
        f = set()
        ans = set()
        for i in xrange(0, len(s) - 10 + 1):
            substr = s[i:i + 10]
            if substr in f:
                ans.add(substr)
            f.add(substr)
        return list(ans)