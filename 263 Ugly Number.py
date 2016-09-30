class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        
        lst = [2, 3, 5]
        def check(x):
            if (x == 0):
                return False
            if (x == 1):
                return True
            for t in lst:
                if x % t == 0:
                    return check(x / t)
            return False
        return check(num)
