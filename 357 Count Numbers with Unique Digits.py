class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 10
        def fac(x):
            return 1 if x == 0 else x * fac(x - 1)
        
        def p(x, y):
            return 0 if x < y else fac(x) / fac(x - y)
        
        ans = 0
        for i in xrange(1, n + 1):
            ans += 9 * p(9, i - 1)
        return ans + 1