class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        steps = (1, 0), (-1, 1)
        n = numRows
        x = y = 0
        dir = 0
        positions = []
        for ch in s:
            positions.append((x, y, ch))
            x += steps[dir][0]
            y += steps[dir][1]
            if x == 0 or x == n - 1:
                dir = dir ^ 1
        res = ''.join([tmp[2] for tmp in sorted(positions)])
        return res