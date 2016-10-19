class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        def dfs(dir, x):
            if x == 1:
                return 1
            if not dir:
                t = 2 * dfs(not dir, x / 2)
            else:
                t = 2 * dfs(not dir, x / 2) - (not (x & 1))
            return t
                
        return dfs(0, n)
