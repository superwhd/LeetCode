class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        f = set()
        while n not in f:
            f.add(n)
            n = sum([int(x) ** 2 for x in str(n)])
        return n == 1