class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        ans = s = sum([A[i] * i for i in xrange(n)])
        sumA = sum(A)
        for i in xrange(1, n):
            s -= sumA
            s += n * A[i - 1]
            ans = max(ans, s)
        return ans
