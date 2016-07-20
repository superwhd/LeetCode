class Solution(object):
    def reverseBits(self, n):
        """
        :type n: int
        :rtype: int
        """
        for i in xrange(0, 16):
            d = (n >> i & 1) ^ (n >> (31 - i) & 1)
            n ^= d << i
            n ^= d << (31 - i)
        return n