class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        mul = -1 if x < 0 else 1;
        ans = int(str(abs(x))[::-1]) * mul
        maxint = 2 ** 31 - 1
        if ans < -maxint - 1 or ans > maxint:
            ans = 0
        return ans