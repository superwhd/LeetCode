class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        def cp(s1, s2):
            i = 0
            while i < len(s1) and i < len(s2):
                if s1[i] != s2[i]:
                    break
                i += 1
            return s1[:i]
        if [] == strs:
            return ''
        return reduce(cp, strs)