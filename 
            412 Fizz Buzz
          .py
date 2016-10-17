class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        for i in xrange(1, n + 1):
            s = ''
            if not i % 3:
                s += 'Fizz'
            if not i % 5:
                s += 'Buzz'
            if not s:
                s = str(i)
            res.append(s)
        return res
