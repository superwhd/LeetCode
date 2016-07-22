class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        fac = 1
        ans = ''
        vis = set()
        k -= 1
        fac = lambda x : 1 if not x else x * fac(x - 1) 
        for i in xrange(n - 1, -1, -1):
            digit = 0
            cnt = k / fac(i) + 1
            while cnt:
                digit += 1
                if digit not in vis:
                    cnt -= 1
            vis.add(digit)
            ans += str(digit)
            k %= fac(i)
        return ans
                