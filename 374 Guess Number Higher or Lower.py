# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):
class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        b = 1 
        e = n
        while True:
            mid = (b + e) / 2
            t = guess(mid)
            if not t:
                return mid
            if 1 == t:
                b = mid + 1
            else:
                e = mid - 1