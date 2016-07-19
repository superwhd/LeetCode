class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        fac = lambda x : 1 if x == 0 else x * fac(x - 1)
        return fac(n * 2) / fac(n + 1) / fac(n)