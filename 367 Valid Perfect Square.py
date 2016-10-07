class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        s = 0
        e = num
        while s <= e:
            mid = s + e >> 1
            if mid ** 2 >= num:
                e = mid - 1
            else:
                s = mid + 1
                
        return s ** 2 == num
