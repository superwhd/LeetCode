class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if len(A) < 3:
            return 0
        diff = [A[i] - A[i - 1] for i in range(1, len(A))]
        i = 0
        ans = 0
        while i < len(diff):
            for j in xrange(i, len(diff) + 1):
                if j >= len(diff) or diff[i] != diff[j]:
                    break
            l = j - i
            ans += l * (l - 1) / 2
            i = j
        return ans
